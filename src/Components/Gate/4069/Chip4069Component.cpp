/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Chip4069Component.cpp
*/

#include "Chip4069Component.hpp"

nts::Tristate nts::Chip4069Component::recompute(std::size_t pin)
{
    return getLink(pin);
}

nts::Chip4069Component::Chip4069Component()
{
    _validPins = {
        Input1, Output1,
        Input2, Output2,
        Input3, Output3,
        Input4, Output4,
        Input5, Output5,
        Input6, Output6,
    };
    _outputPins = {Output1, Output2, Output3, Output4, Output5, Output6};

    notGate1.setLink(NotComponent::Input, *this, Input1);
    this->setLink(Output1, notGate1, NotComponent::Output);

    notGate2.setLink(NotComponent::Input, *this, Input2);
    this->setLink(Output2, notGate2, NotComponent::Output);

    notGate3.setLink(NotComponent::Input, *this, Input3);
    this->setLink(Output3, notGate3, NotComponent::Output);

    notGate4.setLink(NotComponent::Input, *this, Input4);
    this->setLink(Output4, notGate4, NotComponent::Output);

    notGate5.setLink(NotComponent::Input, *this, Input5);
    this->setLink(Output5, notGate5, NotComponent::Output);

    notGate6.setLink(NotComponent::Input, *this, Input6);
    this->setLink(Output6, notGate6, NotComponent::Output);
}
