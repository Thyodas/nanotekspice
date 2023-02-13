/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** XorComponent.cpp
*/

#include "XorComponent.hpp"

nts::Tristate nts::XorComponent::compute(std::size_t pin)
{
    return getLink(pin);
}

nts::XorComponent::XorComponent()
{
    _validPins = {InputA, InputB, Output};
    _outputPins = {Output};
    andGateA.setLink(AndComponent::InputA, *this, InputA);
    notGateA.setLink(NotComponent::Input, *this, InputB);
    andGateA.setLink(AndComponent::InputB, notGateA, NotComponent::Output);

    notGateB.setLink(NotComponent::Input, *this, InputA);
    andGateB.setLink(AndComponent::InputA, notGateB, NotComponent::Output);
    andGateB.setLink(AndComponent::InputB, *this, InputB);

    orGate.setLink(OrComponent::InputA, andGateA, AndComponent::Output);
    orGate.setLink(OrComponent::InputB, andGateB, AndComponent::Output);
    this->setLink(Output, orGate, OrComponent::Output);
}
