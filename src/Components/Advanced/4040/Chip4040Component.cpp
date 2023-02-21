/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Chip4040Component.cpp
*/

#include "Chip4040Component.hpp"

nts::Tristate nts::Chip4040Component::recompute(std::size_t pin)
{
    return getLink(pin);
}

nts::Chip4040Component::Chip4040Component()
{
    _validPins = {Q12, Q6, Q5, Q7, Q4, Q3, Q2, Q11, Q10, Q8, Q9, R, C, Q1};
    _outputPins = {Q12, Q6, Q5, Q7, Q4, Q3, Q2, Q11, Q10, Q8, Q9, Q1};

    notGateClk.setLink(NotComponent::Input, *this, C);

    orGateClk.setLink(OrComponent::InputA, notGateClk, NotComponent::Output);
    orGateClk.setLink(OrComponent::InputB, *this, R);

    flipFlop1.setLink(JKFlipFlopComponent::InK, orGateClk, OrComponent::Output);
    flipFlop1.setLink(JKFlipFlopComponent::InJ, orGateClk, OrComponent::Output);
    flipFlop1.setLink(JKFlipFlopComponent::InClk, orGateClk, OrComponent::Output);
    notGateFF1.setLink(NotComponent::Input, flipFlop1, JKFlipFlopComponent::OutQ);

    flipFlop2.setLink(JKFlipFlopComponent::InK, notGateFF1, NotComponent::Output);
    flipFlop2.setLink(JKFlipFlopComponent::InJ, flipFlop1, NotComponent::Output);
    flipFlop2.setLink(JKFlipFlopComponent::InClk, flipFlop1, JKFlipFlopComponent::OutNQ);
    notGateFF2.setLink(NotComponent::Input, flipFlop2, JKFlipFlopComponent::OutQ);

    flipFlop3.setLink(JKFlipFlopComponent::InK, notGateFF2, NotComponent::Output);
    flipFlop3.setLink(JKFlipFlopComponent::InJ, notGateFF2, NotComponent::Output);
    flipFlop3.setLink(JKFlipFlopComponent::InClk, flipFlop2, JKFlipFlopComponent::OutNQ);
    notGateFF3.setLink(NotComponent::Input, flipFlop3, JKFlipFlopComponent::OutQ);

    flipFlop4.setLink(JKFlipFlopComponent::InK, notGateFF3, NotComponent::Output);
    flipFlop4.setLink(JKFlipFlopComponent::InJ, notGateFF3, NotComponent::Output);
    flipFlop4.setLink(JKFlipFlopComponent::InClk, flipFlop3, JKFlipFlopComponent::OutNQ);
    notGateFF4.setLink(NotComponent::Input, flipFlop4, JKFlipFlopComponent::OutQ);

    flipFlop5.setLink(JKFlipFlopComponent::InK, notGateFF4, NotComponent::Output);
    flipFlop5.setLink(JKFlipFlopComponent::InJ, notGateFF4, NotComponent::Output);
    flipFlop5.setLink(JKFlipFlopComponent::InClk, flipFlop4, JKFlipFlopComponent::OutNQ);
    notGateFF5.setLink(NotComponent::Input, flipFlop5, JKFlipFlopComponent::OutQ);

    flipFlop6.setLink(JKFlipFlopComponent::InK, notGateFF5, NotComponent::Output);
    flipFlop6.setLink(JKFlipFlopComponent::InJ, notGateFF5, NotComponent::Output);
    flipFlop6.setLink(JKFlipFlopComponent::InClk, flipFlop5, JKFlipFlopComponent::OutNQ);
    notGateFF6.setLink(NotComponent::Input, flipFlop6, JKFlipFlopComponent::OutQ);

    flipFlop7.setLink(JKFlipFlopComponent::InK, notGateFF6, NotComponent::Output);
    flipFlop7.setLink(JKFlipFlopComponent::InJ, notGateFF6, NotComponent::Output);
    flipFlop7.setLink(JKFlipFlopComponent::InClk, flipFlop6, JKFlipFlopComponent::OutNQ);
    notGateFF7.setLink(NotComponent::Input, flipFlop7, JKFlipFlopComponent::OutQ);

    flipFlop8.setLink(JKFlipFlopComponent::InK, notGateFF7, NotComponent::Output);
    flipFlop8.setLink(JKFlipFlopComponent::InJ, notGateFF7, NotComponent::Output);
    flipFlop8.setLink(JKFlipFlopComponent::InClk, flipFlop7, JKFlipFlopComponent::OutNQ);
    notGateFF8.setLink(NotComponent::Input, flipFlop8, JKFlipFlopComponent::OutQ);

    flipFlop9.setLink(JKFlipFlopComponent::InK, notGateFF8, NotComponent::Output);
    flipFlop9.setLink(JKFlipFlopComponent::InJ, notGateFF8, NotComponent::Output);
    flipFlop9.setLink(JKFlipFlopComponent::InClk, flipFlop8, JKFlipFlopComponent::OutNQ);
    notGateFF9.setLink(NotComponent::Input, flipFlop9, JKFlipFlopComponent::OutQ);

    flipFlop10.setLink(JKFlipFlopComponent::InK, notGateFF9, NotComponent::Output);
    flipFlop10.setLink(JKFlipFlopComponent::InJ, notGateFF9, NotComponent::Output);
    flipFlop10.setLink(JKFlipFlopComponent::InClk, flipFlop9, JKFlipFlopComponent::OutNQ);
    notGateFF10.setLink(NotComponent::Input, flipFlop10, JKFlipFlopComponent::OutQ);

    flipFlop11.setLink(JKFlipFlopComponent::InK, notGateFF10, NotComponent::Output);
    flipFlop11.setLink(JKFlipFlopComponent::InJ, notGateFF10, NotComponent::Output);
    flipFlop11.setLink(JKFlipFlopComponent::InClk, flipFlop10, JKFlipFlopComponent::OutNQ);
    notGateFF11.setLink(NotComponent::Input, flipFlop11, JKFlipFlopComponent::OutQ);

    flipFlop12.setLink(JKFlipFlopComponent::InK, notGateFF11, NotComponent::Output);
    flipFlop12.setLink(JKFlipFlopComponent::InJ, notGateFF11, NotComponent::Output);
    flipFlop12.setLink(JKFlipFlopComponent::InClk, flipFlop11, JKFlipFlopComponent::OutNQ);

    this->setLink(Q1, flipFlop1, JKFlipFlopComponent::OutQ);
    this->setLink(Q2, flipFlop2, JKFlipFlopComponent::OutQ);
    this->setLink(Q3, flipFlop3, JKFlipFlopComponent::OutQ);
    this->setLink(Q4, flipFlop4, JKFlipFlopComponent::OutQ);
    this->setLink(Q5, flipFlop5, JKFlipFlopComponent::OutQ);
    this->setLink(Q6, flipFlop6, JKFlipFlopComponent::OutQ);
    this->setLink(Q7, flipFlop7, JKFlipFlopComponent::OutQ);
    this->setLink(Q8, flipFlop8, JKFlipFlopComponent::OutQ);
    this->setLink(Q9, flipFlop9, JKFlipFlopComponent::OutQ);
    this->setLink(Q10, flipFlop10, JKFlipFlopComponent::OutQ);
    this->setLink(Q11, flipFlop11, JKFlipFlopComponent::OutQ);
    this->setLink(Q12, flipFlop12, JKFlipFlopComponent::OutQ);
}
