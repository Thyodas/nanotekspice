/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Nand3Component.cpp
*/

#include "Nand3Component.hpp"

nts::Tristate nts::Nand3Component::recompute(std::size_t pin)
{
    return getLink(pin);
}

nts::Nand3Component::Nand3Component()
{
    _validPins = {InputA, InputB, InputC, Output};
    _outputPins = {Output};

    nandGateA.setLink(nts::NandComponent::InputA, *this, InputA);
    nandGateA.setLink(nts::NandComponent::InputB, *this, InputB);

    nandGateB.setLink(nts::NandComponent::InputA, nandGateA, nts::NandComponent::Output);
    nandGateB.setLink(nts::NandComponent::InputB, nandGateA, nts::NandComponent::Output);

    nandGateC.setLink(nts::NandComponent::InputA, nandGateB, nts::NandComponent::Output);
    nandGateC.setLink(nts::NandComponent::InputB, *this, InputC);

    this->setLink(Output, nandGateC, nts::NandComponent::Output);
}
