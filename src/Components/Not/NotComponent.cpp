/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** NotComponent.cpp
*/

#include "NotComponent.hpp"

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (pin != 2)
        return getLink(pin);
    Tristate a = getLink(1);
    if (a == Undefined)
        return Undefined;
    return (Tristate)(!a);
}

nts::NotComponent::NotComponent()
{
    _validPins = {1, 2};
}
