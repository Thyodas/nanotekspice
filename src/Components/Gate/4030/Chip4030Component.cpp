/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Chip4030Component.cpp
*/

#include "Chip4030Component.hpp"

nts::Tristate nts::Chip4030Component::compute(std::size_t pin)
{
    return getLink(pin);
}

nts::Chip4030Component::Chip4030Component()
{
    _validPins = {
        Input1A, Input1B, Output1Y,
        Input2A, Input2B, Output2Y,
        Input3A, Input3B, Output3Y,
        Input4A, Input4B, Output4Y,
    };

    xorGate1.setLink(XorComponent::InputA, *this, Input1A);
    xorGate1.setLink(XorComponent::InputB, *this, Input1B);
    this->setLink(Output1Y, xorGate1, XorComponent::Output);

    xorGate2.setLink(XorComponent::InputA, *this, Input2A);
    xorGate2.setLink(XorComponent::InputB, *this, Input2B);
    this->setLink(Output2Y, xorGate2, XorComponent::Output);

    xorGate3.setLink(XorComponent::InputA, *this, Input3A);
    xorGate3.setLink(XorComponent::InputB, *this, Input3B);
    this->setLink(Output3Y, xorGate3, XorComponent::Output);

    xorGate4.setLink(XorComponent::InputA, *this, Input4A);
    xorGate4.setLink(XorComponent::InputB, *this, Input4B);
    this->setLink(Output4Y, xorGate4, XorComponent::Output);
}
