/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** NandComponent.cpp
*/

#include "NandComponent.hpp"

nts::Tristate nts::NandComponent::compute(std::size_t pin)
{
    return getLink(pin);
}

nts::NandComponent::NandComponent()
{
    _validPins = {InputA, InputB, Output};
    _outputPins = {Output};

    andGate.setLink(AndComponent::InputA, *this, InputA);
    andGate.setLink(AndComponent::InputB, *this, InputB);
    notGate.setLink(NotComponent::Input, andGate, AndComponent::Output);
    this->setLink(Output, notGate, NotComponent::Output);
}
