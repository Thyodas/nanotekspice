/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"

void nts::AComponent::simulate(std::size_t tick)
{
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    auto pair = std::make_pair(otherPin, &other);
    if (_linkMap.find(pin) != _linkMap.end() && _linkMap.at(pin) == pair)
        return;
    _linkMap[pin] = pair;
    other.setLink(otherPin, *this, pin);
}

nts::AComponent::AComponent()
: _tick(1)
{
}

bool nts::AComponent::isValidPin(std::size_t pin) const
{
    return _validPins.find(pin) != _validPins.end();
}

nts::Tristate nts::AComponent::getLink(std::size_t pin) const
{
    auto pair = _linkMap.at(pin);
    return pair.second->compute(pair.first);
}
