/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Chip4017Component.cpp
*/

#include "Chip4017Component.hpp"

nts::Tristate nts::Chip4017Component::recompute(std::size_t pin)
{
    return getLink(pin);
}

nts::Chip4017Component::Chip4017Component()
{
    _validPins = {Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, QB5_9, CP1, CP0, MR};
    _outputPins = {Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, QB5_9};

    notGateCP1.setLink(NotComponent::Input, *this, CP1);

    andGateCP.setLink(AndComponent::InputA, notGateCP1, NotComponent::Output);
    andGateCP.setLink(AndComponent::InputB, *this, CP0);

    orGateFF.setLink(OrComponent::InputA, flipFlop3, DFlipFlopComponent::OutQ);
    orGateFF.setLink(OrComponent::InputB, flipFlop1, DFlipFlopComponent::OutQ);

    andGateFF.setLink(AndComponent::InputA, orGateFF, OrComponent::Output);
    andGateFF.setLink(AndComponent::InputB, flipFlop2, DFlipFlopComponent::OutQ);

    flipFlop1.setLink(DFlipFlopComponent::InSet, falseGate, FalseComponent::Output);
    flipFlop1.setLink(DFlipFlopComponent::InRst, *this, MR);
    flipFlop1.setLink(DFlipFlopComponent::InData, flipFlop5, DFlipFlopComponent::OutNQ);
    flipFlop1.setLink(DFlipFlopComponent::InClk, andGateCP, AndComponent::Output);

    flipFlop2.setLink(DFlipFlopComponent::InSet, falseGate, FalseComponent::Output);
    flipFlop2.setLink(DFlipFlopComponent::InRst, *this, MR);
    flipFlop2.setLink(DFlipFlopComponent::InData, flipFlop1, DFlipFlopComponent::OutQ);
    flipFlop2.setLink(DFlipFlopComponent::InClk, andGateCP, AndComponent::Output);

    flipFlop3.setLink(DFlipFlopComponent::InSet, falseGate, FalseComponent::Output);
    flipFlop3.setLink(DFlipFlopComponent::InRst, *this, MR);
    flipFlop3.setLink(DFlipFlopComponent::InData, andGateFF, AndComponent::Output);
    flipFlop3.setLink(DFlipFlopComponent::InClk, andGateCP, AndComponent::Output);

    flipFlop4.setLink(DFlipFlopComponent::InSet, falseGate, FalseComponent::Output);
    flipFlop4.setLink(DFlipFlopComponent::InRst, *this, MR);
    flipFlop4.setLink(DFlipFlopComponent::InData, flipFlop3, DFlipFlopComponent::OutQ);
    flipFlop4.setLink(DFlipFlopComponent::InClk, andGateCP, AndComponent::Output);

    flipFlop5.setLink(DFlipFlopComponent::InSet, falseGate, FalseComponent::Output);
    flipFlop5.setLink(DFlipFlopComponent::InRst, *this, MR);
    flipFlop5.setLink(DFlipFlopComponent::InData, flipFlop4, DFlipFlopComponent::OutQ);
    flipFlop5.setLink(DFlipFlopComponent::InClk, andGateCP, AndComponent::Output);

    norGateQ0.setLink(NorComponent::InputA, flipFlop5, DFlipFlopComponent::OutQ);
    norGateQ0.setLink(NorComponent::InputB, flipFlop1, DFlipFlopComponent::OutQ);

    norGateQ1.setLink(NorComponent::InputA, flipFlop2, DFlipFlopComponent::OutQ);
    norGateQ1.setLink(NorComponent::InputB, flipFlop1, DFlipFlopComponent::OutNQ);

    norGateQ2.setLink(NorComponent::InputA, flipFlop2, DFlipFlopComponent::OutNQ);
    norGateQ2.setLink(NorComponent::InputB, flipFlop3, DFlipFlopComponent::OutQ);

    norGateQ3.setLink(NorComponent::InputA, flipFlop4, DFlipFlopComponent::OutQ);
    norGateQ3.setLink(NorComponent::InputB, flipFlop3, DFlipFlopComponent::OutNQ);

    norGateQ4.setLink(NorComponent::InputA, flipFlop5, DFlipFlopComponent::OutQ);
    norGateQ4.setLink(NorComponent::InputB, flipFlop4, DFlipFlopComponent::OutNQ);

    norGateQ5.setLink(NorComponent::InputA, flipFlop1, DFlipFlopComponent::OutNQ);
    norGateQ5.setLink(NorComponent::InputB, flipFlop5, DFlipFlopComponent::OutNQ);

    norGateQ6.setLink(NorComponent::InputA, flipFlop1, DFlipFlopComponent::OutQ);
    norGateQ6.setLink(NorComponent::InputB, flipFlop2, DFlipFlopComponent::OutNQ);

    norGateQ7.setLink(NorComponent::InputA, flipFlop2, DFlipFlopComponent::OutQ);
    norGateQ7.setLink(NorComponent::InputB, flipFlop3, DFlipFlopComponent::OutNQ);

    norGateQ8.setLink(NorComponent::InputA, flipFlop4, DFlipFlopComponent::OutNQ);
    norGateQ8.setLink(NorComponent::InputB, flipFlop3, DFlipFlopComponent::OutQ);

    norGateQ9.setLink(NorComponent::InputA, flipFlop4, DFlipFlopComponent::OutQ);
    norGateQ9.setLink(NorComponent::InputB, flipFlop5, DFlipFlopComponent::OutNQ);

    this->setLink(Q0, norGateQ0, NorComponent::Output);
    this->setLink(Q1, norGateQ1, NorComponent::Output);
    this->setLink(Q2, norGateQ2, NorComponent::Output);
    this->setLink(Q3, norGateQ3, NorComponent::Output);
    this->setLink(Q4, norGateQ4, NorComponent::Output);
    this->setLink(Q5, norGateQ5, NorComponent::Output);
    this->setLink(Q6, norGateQ6, NorComponent::Output);
    this->setLink(Q7, norGateQ7, NorComponent::Output);
    this->setLink(Q8, norGateQ8, NorComponent::Output);
    this->setLink(Q9, norGateQ9, NorComponent::Output);
    this->setLink(QB5_9, flipFlop5, DFlipFlopComponent::OutNQ);
}
