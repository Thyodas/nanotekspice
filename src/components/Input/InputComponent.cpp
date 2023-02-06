/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** InputComponent.cpp
*/

#include "InputComponent.hpp"

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    return getLink(pin);
}

nts::InputComponent::InputComponent()
{
    _validPins = {1};
}
