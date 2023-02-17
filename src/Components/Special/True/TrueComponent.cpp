/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** TrueComponent.cpp
*/

#include "TrueComponent.hpp"

nts::Tristate nts::TrueComponent::recompute(__attribute__((unused)) std::size_t pin)
{
    return True;
}

nts::TrueComponent::TrueComponent()
{
    _validPins = {Output};
    _outputPins = {Output};
}
