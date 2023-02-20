/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** And3Component.cpp
*/

#include "And3Component.hpp"

nts::Tristate nts::And3Component::recompute(std::size_t pin)
{
    return getLink(pin);
}

nts::And3Component::And3Component()
{
    _validPins = {InputA, InputB, InputC, Output};
    _outputPins = {Output};

    andGateA.setLink(AndComponent::InputA, *this, InputA);
    andGateA.setLink(AndComponent::InputB, *this, InputB);
    andGateB.setLink(AndComponent::InputA, andGateA, AndComponent::Output);
    andGateB.setLink(AndComponent::InputB, *this, InputC);
    this->setLink(Output, andGateB, AndComponent::Output);
}
