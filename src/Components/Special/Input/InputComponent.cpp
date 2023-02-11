/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** InputComponent.cpp
*/

#include "InputComponent.hpp"

nts::Tristate nts::InputComponent::compute(__attribute__((unused)) std::size_t pin)
{
    return _value;
}

nts::InputComponent::InputComponent()
: _value(Undefined), _newValue(Undefined)
{
    _validPins = {Output};
}

void nts::InputComponent::setValue(nts::Tristate value)
{
    _newValue = value;
}

void nts::InputComponent::simulate(__attribute__((unused)) std::size_t tick)
{
    _value = _newValue;
}
