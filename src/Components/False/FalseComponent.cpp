/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** FalseComponent.cpp
*/

#include "FalseComponent.hpp"

nts::Tristate nts::FalseComponent::compute(__attribute__((unused)) std::size_t pin)
{
    return False;
}

nts::FalseComponent::FalseComponent()
{
    _validPins = {Output};
}
