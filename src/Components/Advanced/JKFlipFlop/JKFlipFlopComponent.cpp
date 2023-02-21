/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** JKFlipFlopComponent.cpp
*/

#include "JKFlipFlopComponent.hpp"

nts::Tristate nts::JKFlipFlopComponent::recompute(std::size_t pin)
{
    return getLink(pin);
}

/*
 * For more details see:
 * https://dcaclab.com/blog/j-k-flip-flop-explained-in-detail/
 */
nts::JKFlipFlopComponent::JKFlipFlopComponent()
{
    _validPins = {InJ, InClk, InK, InRst, OutQ, OutNQ};
    _outputPins = {OutNQ, OutQ};
    _value = Undefined;
    _prevClock = Undefined;

    andGateJ.setLink(AndComponent::InputA, *this, InJ);
    andGateJ.setLink(AndComponent::InputB, *this, OutNQ);

    notGateK.setLink(NotComponent::Input, *this, InK);

    andGateK.setLink(AndComponent::InputA, *this, OutQ);
    andGateK.setLink(AndComponent::InputB, notGateK, NotComponent::Output);

    orGate.setLink(OrComponent::InputA, andGateJ, AndComponent::Output);
    orGate.setLink(OrComponent::InputB, andGateK, AndComponent::Output);

    flipFlop.setLink(DFlipFlopComponent::InData, orGate, OrComponent::Output);
    flipFlop.setLink(DFlipFlopComponent::InClk, *this, InClk);
    flipFlop.setLink(DFlipFlopComponent::InSet, falseGate, FalseComponent::Output);
    flipFlop.setLink(DFlipFlopComponent::InRst, *this, InRst);

    this->setLink(OutQ, flipFlop, DFlipFlopComponent::OutQ);
    this->setLink(OutNQ, flipFlop, DFlipFlopComponent::OutNQ);

    _computeCacheMap[OutQ] = True;
    _computeCacheMap[OutNQ] = False;
    //flipFlop.compute(DFlipFlopComponent::OutQ);
    //flipFlop.compute(DFlipFlopComponent::OutNQ);
    //_computeCacheMap.clear();
}
