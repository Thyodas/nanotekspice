/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Chip4071Component.cpp
*/

#include "Chip4071Component.hpp"

nts::Tristate nts::Chip4071Component::compute(std::size_t pin)
{
    return getLink(pin);
}

nts::Chip4071Component::Chip4071Component()
{
    _validPins = {
        Input1A, Input1B, Output1Y,
        Input2A, Input2B, Output2Y,
        Input3A, Input3B, Output3Y,
        Input4A, Input4B, Output4Y,
    };
    _outputPins = {Output1Y, Output2Y, Output3Y, Output4Y};

    orGate1.setLink(OrComponent::InputA, *this, Input1A);
    orGate1.setLink(OrComponent::InputB, *this, Input1B);
    this->setLink(Output1Y, orGate1, OrComponent::Output);

    orGate2.setLink(OrComponent::InputA, *this, Input2A);
    orGate2.setLink(OrComponent::InputB, *this, Input2B);
    this->setLink(Output2Y, orGate2, OrComponent::Output);

    orGate3.setLink(OrComponent::InputA, *this, Input3A);
    orGate3.setLink(OrComponent::InputB, *this, Input3B);
    this->setLink(Output3Y, orGate3, OrComponent::Output);

    orGate4.setLink(OrComponent::InputA, *this, Input4A);
    orGate4.setLink(OrComponent::InputB, *this, Input4B);
    this->setLink(Output4Y, orGate4, OrComponent::Output);
}
