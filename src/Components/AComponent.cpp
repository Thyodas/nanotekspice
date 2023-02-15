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
        throw nts::Error("Invalid pin for this component.");
    if (_linkMap.find(pin) != _linkMap.end())
        return;
    _linkMap[pin] = std::make_pair(otherPin, &other);
}

nts::AComponent::AComponent()
: _tick(1)
{
}

bool nts::AComponent::isValidPin(std::size_t pin) const
{
    return _validPins.find(pin) != _validPins.end();
}

nts::Tristate nts::AComponent::getLink(std::size_t pin)
{
    if (_linkMap.find(pin) == _linkMap.end())
        return Undefined;
    if (_computeCacheMap.find(pin) != _computeCacheMap.end())
        return _computeCacheMap.at(pin);
    auto pair = _linkMap.at(pin);
    Tristate result = pair.second->compute(pair.first);
    _computeCacheMap[pin] = result;
    return result;
}

void nts::AComponent::setValue(__attribute__((unused)) nts::Tristate value)
{
    throw nts::Error("Impossible to set a value to a component "
                     "that is neither a clock nor an input.");
}
