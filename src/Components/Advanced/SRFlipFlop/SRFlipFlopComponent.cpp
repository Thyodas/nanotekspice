/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-guillaume.hein
** File description:
** SRFLipFlopComponent.cpp
*/

#include "SRFlipFlopComponent.hpp"

nts::Tristate nts::SRFlipFlopComponent::recompute(std::size_t pin)
{
    return getLink(pin);
}

nts::SRFlipFlopComponent::SRFlipFlopComponent()
{
    _validPins = {InSet, InRst, OutNQ, OutQ};
    _outputPins = {OutNQ, OutQ};

    norGateA.setLink(NorComponent::InputA, *this, InRst);
    norGateB.setLink(NorComponent::InputA, *this, InSet);

    norGateA.setLink(NorComponent::InputB, norGateB, NorComponent::Output);
    norGateB.setLink(NorComponent::InputB, norGateA, NorComponent::Output);

    this->setLink(OutQ, norGateA, NorComponent::Output);
    this->setLink(OutNQ, norGateB, NorComponent::Output);
}