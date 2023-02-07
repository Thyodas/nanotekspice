/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** NotComponent.cpp
*/

#include "NotComponent.hpp"

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (pin != Output)
        return getLink(pin);
    Tristate a = getLink(Input);
    if (a == Undefined)
        return Undefined;
    return (Tristate)(!a);
}

nts::NotComponent::NotComponent()
{
    _validPins = {Input, Output};
}
