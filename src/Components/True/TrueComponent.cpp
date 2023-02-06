/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** TrueComponent.cpp
*/

#include "TrueComponent.hpp"

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    return True;
}

nts::TrueComponent::TrueComponent()
{
    _validPins = {1};
}
