/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Chip4001Component.cpp
*/

#include "Chip4001Component.hpp"

nts::Tristate nts::Chip4001Component::compute(std::size_t pin)
{
    return getLink(pin);
}

nts::Chip4001Component::Chip4001Component()
{
    _validPins = {
        Input1A, Input1B, Output1Y,
        Input2A, Input2B, Output2Y,
        Input3A, Input3B, Output3Y,
        Input4A, Input4B, Output4Y,
    };
    _outputPins = {Output1Y, Output2Y, Output3Y, Output4Y};

    norGate1.setLink(NorComponent::InputA, *this, Input1A);
    norGate1.setLink(NorComponent::InputB, *this, Input1B);
    this->setLink(Output1Y, norGate1, NorComponent::Output);

    norGate2.setLink(NorComponent::InputA, *this, Input2A);
    norGate2.setLink(NorComponent::InputB, *this, Input2B);
    this->setLink(Output2Y, norGate2, NorComponent::Output);

    norGate3.setLink(NorComponent::InputA, *this, Input3A);
    norGate3.setLink(NorComponent::InputB, *this, Input3B);
    this->setLink(Output3Y, norGate3, NorComponent::Output);

    norGate4.setLink(NorComponent::InputA, *this, Input4A);
    norGate4.setLink(NorComponent::InputB, *this, Input4B);
    this->setLink(Output4Y, norGate4, NorComponent::Output);
}
