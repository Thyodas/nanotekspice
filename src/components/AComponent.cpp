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

nts::Tristate nts::AComponent::compute(std::size_t pin)
{
    return Undefined;
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    _linkMap[pin] = std::make_pair(otherPin, &other);
    other.setLink(otherPin, *this, pin);
}

nts::AComponent::AComponent()
: _tick(1)
{
}
