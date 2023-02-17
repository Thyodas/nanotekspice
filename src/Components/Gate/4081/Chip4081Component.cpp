/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Chip4081Component.cpp
*/

#include "Chip4081Component.hpp"

nts::Tristate nts::Chip4081Component::recompute(std::size_t pin)
{
    return getLink(pin);
}

nts::Chip4081Component::Chip4081Component()
{
    _validPins = {
        Input1A, Input1B, Output1Y,
        Input2A, Input2B, Output2Y,
        Input3A, Input3B, Output3Y,
        Input4A, Input4B, Output4Y,
    };
    _outputPins = {Output1Y, Output2Y, Output3Y, Output4Y};

    andGate1.setLink(AndComponent::InputA, *this, Input1A);
    andGate1.setLink(AndComponent::InputB, *this, Input1B);
    this->setLink(Output1Y, andGate1, AndComponent::Output);

    andGate2.setLink(AndComponent::InputA, *this, Input2A);
    andGate2.setLink(AndComponent::InputB, *this, Input2B);
    this->setLink(Output2Y, andGate2, AndComponent::Output);

    andGate3.setLink(AndComponent::InputA, *this, Input3A);
    andGate3.setLink(AndComponent::InputB, *this, Input3B);
    this->setLink(Output3Y, andGate3, AndComponent::Output);

    andGate4.setLink(AndComponent::InputA, *this, Input4A);
    andGate4.setLink(AndComponent::InputB, *this, Input4B);
    this->setLink(Output4Y, andGate4, AndComponent::Output);
}
