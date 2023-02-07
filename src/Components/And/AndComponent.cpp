/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** AndComponent.cpp
*/

#include "AndComponent.hpp"

nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    if (pin != 3)
        return getLink(pin);
    Tristate a = getLink(1);
    Tristate b = getLink(2);
    if (a == False || b == False)
        return False;
    if (a == True && b == True)
        return True;
    return Undefined;
}

nts::AndComponent::AndComponent()
{
    _validPins = {1, 2, 3};
}
