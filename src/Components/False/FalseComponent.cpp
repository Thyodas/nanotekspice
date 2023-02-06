/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** FalseComponent.cpp
*/

#include "FalseComponent.hpp"

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    return False;
}

nts::FalseComponent::FalseComponent()
{
    _validPins = {1};
}
