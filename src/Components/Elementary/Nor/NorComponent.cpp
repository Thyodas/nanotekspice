/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** NorComponent.cpp
*/

#include "NorComponent.hpp"

nts::Tristate nts::NorComponent::recompute(std::size_t pin)
{
    return getLink(pin);
}

nts::NorComponent::NorComponent()
{
    _validPins = {InputA, InputB, Output};
    _outputPins = {Output};

    orGate.setLink(OrComponent::InputA, *this, InputA);
    orGate.setLink(OrComponent::InputB, *this, InputB);
    notGate.setLink(NotComponent::Input, orGate, OrComponent::Output);
    this->setLink(Output, notGate, NotComponent::Output);
}
