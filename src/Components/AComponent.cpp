/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"
#include "../Circuit.hpp"

void nts::AComponent::resetCache(void)
{
    if (_computeCacheMap.empty())
        return;
    _prevComputeCacheMap.clear();
    _prevComputeCacheMap = _computeCacheMap;
    _computeCacheMap.clear();
    for (const auto &item: _linkMap)
        item.second.second->resetCache();
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
    if (!_inLoop && _computeCacheMap.contains(pin))
        return _computeCacheMap.at(pin);
    if (_prevComputeCacheMap.contains(pin))
        _computeCacheMap[pin] = _prevComputeCacheMap.at(pin);
    else {
        _computeCacheMap[pin] = Undefined;
    }
    _inLoop = true;
    Tristate result = recompute(pin);
    _inLoop = false;
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
