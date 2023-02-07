/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** InputComponent.cpp
*/

#include "InputComponent.hpp"

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    return _value;
}

nts::InputComponent::InputComponent()
: _value(Undefined)
{
    _validPins = {1};
}

void nts::InputComponent::setValue(nts::Tristate value)
{
    _value = value;
}
