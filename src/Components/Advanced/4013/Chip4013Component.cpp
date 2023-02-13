/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Chip4013Component.cpp
*/

#include "Chip4013Component.hpp"

nts::Tristate nts::Chip4013Component::compute(std::size_t pin)
{
    return getLink(pin);
}

nts::Chip4013Component::Chip4013Component()
{
    _validPins = {
        OutQ1, OutNQ1, InClk1, InRst1, InData1, InSet1, InSet2, InData2,
        InRst2, InClk2, OutNQ2, OutQ2,
    };
    _outputPins = {OutQ1, OutQ2, OutNQ1, OutNQ2};

    flipFlop1.setLink(DFlipFlopComponent::InClk, *this, InClk1);
    flipFlop1.setLink(DFlipFlopComponent::InRst, *this, InRst1);
    flipFlop1.setLink(DFlipFlopComponent::InData, *this, InData1);
    flipFlop1.setLink(DFlipFlopComponent::InSet, *this, InSet1);
    this->setLink(OutQ1, flipFlop1, DFlipFlopComponent::OutQ);
    this->setLink(OutNQ1, flipFlop1, DFlipFlopComponent::OutNQ);

    flipFlop2.setLink(DFlipFlopComponent::InClk, *this, InClk2);
    flipFlop2.setLink(DFlipFlopComponent::InRst, *this, InRst2);
    flipFlop2.setLink(DFlipFlopComponent::InData, *this, InData2);
    flipFlop2.setLink(DFlipFlopComponent::InSet, *this, InSet2);
    this->setLink(OutQ2, flipFlop2, DFlipFlopComponent::OutQ);
    this->setLink(OutNQ2, flipFlop2, DFlipFlopComponent::OutNQ);
}
