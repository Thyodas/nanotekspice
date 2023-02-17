/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Chip4011Component.cpp
*/

#include "Chip4011Component.hpp"

nts::Tristate nts::Chip4011Component::recompute(std::size_t pin)
{
    return getLink(pin);
}

nts::Chip4011Component::Chip4011Component()
{
    _validPins = {
        Input1A, Input1B, Output1Y,
        Input2A, Input2B, Output2Y,
        Input3A, Input3B, Output3Y,
        Input4A, Input4B, Output4Y,
    };
    _outputPins = {Output1Y, Output2Y, Output3Y, Output4Y};

    nandGate1.setLink(NandComponent::InputA, *this, Input1A);
    nandGate1.setLink(NandComponent::InputB, *this, Input1B);
    this->setLink(Output1Y, nandGate1, NandComponent::Output);

    nandGate2.setLink(NandComponent::InputA, *this, Input2A);
    nandGate2.setLink(NandComponent::InputB, *this, Input2B);
    this->setLink(Output2Y, nandGate2, NandComponent::Output);

    nandGate3.setLink(NandComponent::InputA, *this, Input3A);
    nandGate3.setLink(NandComponent::InputB, *this, Input3B);
    this->setLink(Output3Y, nandGate3, NandComponent::Output);

    nandGate4.setLink(NandComponent::InputA, *this, Input4A);
    nandGate4.setLink(NandComponent::InputB, *this, Input4B);
    this->setLink(Output4Y, nandGate4, NandComponent::Output);
}
