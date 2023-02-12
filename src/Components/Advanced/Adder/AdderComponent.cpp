/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** AdderComponent.cpp
*/

#include "AdderComponent.hpp"

nts::Tristate nts::AdderComponent::compute(std::size_t pin)
{
    return getLink(pin);
}

nts::AdderComponent::AdderComponent()
{
    _validPins = {InputA, InputB, CarryInput, SumOutput, CarryOutput};

    halfAdderGateA.setLink(nts::HalfAdderComponent::InputA, *this, InputA);
    halfAdderGateA.setLink(nts::HalfAdderComponent::InputB, *this, InputB);

    halfAdderGateB.setLink(nts::HalfAdderComponent::InputA, halfAdderGateA, SumOutput);
    halfAdderGateB.setLink(nts::HalfAdderComponent::InputB, *this, CarryInput);

    orGate.setLink(nts::OrComponent::InputA, halfAdderGateB, nts::HalfAdderComponent::CarryOutput);
    orGate.setLink(nts::OrComponent::InputB, halfAdderGateA, nts::HalfAdderComponent::CarryOutput);

    this->setLink(SumOutput, halfAdderGateB, nts::HalfAdderComponent::SumOutput);
    this->setLink(CarryOutput, orGate, nts::OrComponent::Output);
}
