/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** OutputComponent.cpp
*/

#include "OutputComponent.hpp"

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    return getLink(pin);
}

nts::OutputComponent::OutputComponent()
{
    _validPins = {Input};
}
