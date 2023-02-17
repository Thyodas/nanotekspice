/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"
#include "../Circuit.hpp"

std::unordered_set<nts::IComponent *> nts::AComponent::_ringList = {};
std::unordered_set<nts::IComponent *> nts::AComponent::_ringCheckedList = {};

void nts::AComponent::resetCache(void)
{
    if (_computeCacheMap.empty())
        return;
    _prevComputeCacheMap = _computeCacheMap;
    _computeCacheMap.clear();
    for (const auto &item: _linkMap)
        item.second.second->resetCache();
    _ringList.clear();
    _ringCheckedList.clear();
}

void nts::AComponent::simulate(__attribute__((unused)) std::size_t tick)
{
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (!isValidPin(pin))
        throw nts::Error("Invalid pin '" + std::to_string(pin) + "' for this component.");
    if (_linkMap.contains(pin))
        return;
    _linkMap[pin] = std::make_pair(otherPin, &other);
}

nts::AComponent::AComponent()
: _tick(1)
{
}

bool nts::AComponent::isValidPin(std::size_t pin) const
{
    return _validPins.contains(pin);
}

nts::Tristate nts::AComponent::compute(std::size_t pin)
{
    if (_computeCacheMap.contains(pin))
        return _computeCacheMap.at(pin);
    if (_ringList.contains(this)) {
        _ringList.erase(this);
        if (_prevComputeCacheMap.contains(pin))
            _computeCacheMap[pin] = _prevComputeCacheMap.at(pin);
        else {
            _computeCacheMap[pin] = Undefined;
        }
    }
    Tristate result = recompute(pin);
    _computeCacheMap[pin] = result;
    return result;
}

nts::Tristate nts::AComponent::getLink(std::size_t pin)
{
    if (!_linkMap.contains(pin))
        return Undefined;
    auto pair = _linkMap.at(pin);
    return pair.second->compute(pair.first);
}

void nts::AComponent::setValue(__attribute__((unused)) nts::Tristate value)
{
    throw nts::Error("Impossible to set a value to a component "
                     "that is neither a clock nor an input.");
}

void nts::AComponent::findRing(nts::IComponent *ringStart,
                               std::unordered_set<IComponent *> pathHistory)
{
    if (_ringList.contains(this))
        return;
    if (!pathHistory.empty() && this == ringStart) {
        _ringList.insert(this);
        return;
    }
    if (pathHistory.contains(this))
        return;
    pathHistory.insert(this);
    for (const auto &item: _linkMap) {
        if (!_outputPins.contains(item.first))
            item.second.second->findRing(ringStart, pathHistory);
    }
    if (_ringCheckedList.contains(this))
        return;
    _ringCheckedList.insert(this);
    for (const auto &item: _linkMap) {
        item.second.second->findRing(item.second.second, {});
    }
}
