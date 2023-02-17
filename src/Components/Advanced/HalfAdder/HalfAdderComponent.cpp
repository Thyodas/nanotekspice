/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** HalfAdderComponent.cpp
*/

#include "HalfAdderComponent.hpp"

nts::Tristate nts::HalfAdderComponent::recompute(std::size_t pin)
{
    return getLink(pin);
}

nts::HalfAdderComponent::HalfAdderComponent()
{
    _validPins = {InputA, InputB, SumOutput, CarryOutput};
    _outputPins = {SumOutput, CarryOutput};

    xorGate.setLink(nts::XorComponent::InputA, *this, InputA);
    xorGate.setLink(nts::XorComponent::InputB, *this, InputB);

    andGate.setLink(nts::AndComponent::InputA, *this, InputA);
    andGate.setLink(nts::XorComponent::InputB, *this, InputB);

    this->setLink(SumOutput, xorGate, nts::XorComponent::Output);
    this->setLink(CarryOutput, andGate, nts::AndComponent::Output);
}
