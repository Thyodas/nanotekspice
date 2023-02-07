/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** OrComponent.cpp
*/

#include "OrComponent.hpp"

nts::Tristate nts::OrComponent::compute(std::size_t pin)
{
    if (pin != Output)
        return getLink(pin);
    Tristate a = getLink(InputA);
    Tristate b = getLink(InputB);
    if (a == True || b == True)
        return True;
    if (a == False && b == False)
        return False;
    return Undefined;
}

nts::OrComponent::OrComponent()
{
    _validPins = {InputA, InputB, Output};
}
