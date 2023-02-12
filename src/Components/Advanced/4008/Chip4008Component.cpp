/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Chip4008Component.cpp
*/

#include "Chip4008Component.hpp"

nts::Tristate nts::Chip4008Component::compute(std::size_t pin)
{
    return getLink(pin);
}

nts::Chip4008Component::Chip4008Component()
{
    _validPins = {InA1, InA2, InA3, InA4, InB1, InB2, InB3, InB4,
                  OutCO, OutS1, OutS2, OutS3, OutS4};

    adder1.setLink(nts::AdderComponent::InputA, *this, InA1);
    adder1.setLink(nts::AdderComponent::InputB, *this, InB1);
    adder1.setLink(nts::AdderComponent::CarryInput, *this, InC1);
    this->setLink(OutS1, adder1, nts::AdderComponent::SumOutput);

    adder2.setLink(nts::AdderComponent::InputA, *this, InA2);
    adder2.setLink(nts::AdderComponent::InputB, *this, InB2);
    adder2.setLink(nts::AdderComponent::CarryInput, adder1, nts::AdderComponent::CarryOutput);
    this->setLink(OutS2, adder2, nts::AdderComponent::SumOutput);

    adder3.setLink(nts::AdderComponent::InputA, *this, InA3);
    adder3.setLink(nts::AdderComponent::InputB, *this, InB3);
    adder3.setLink(nts::AdderComponent::CarryInput, adder2, nts::AdderComponent::CarryOutput);
    this->setLink(OutS3, adder3, nts::AdderComponent::SumOutput);

    adder4.setLink(nts::AdderComponent::InputA, *this, InA4);
    adder4.setLink(nts::AdderComponent::InputB, *this, InB4);
    adder4.setLink(nts::AdderComponent::CarryInput, adder3, nts::AdderComponent::CarryOutput);
    this->setLink(OutS4, adder4, nts::AdderComponent::SumOutput);
    this->setLink(OutCO, adder4, nts::AdderComponent::CarryOutput);
}
