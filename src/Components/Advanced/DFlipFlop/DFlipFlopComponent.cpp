/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** DFlipFlopComponent.cpp
*/

#include "DFlipFlopComponent.hpp"

nts::Tristate nts::DFlipFlopComponent::recompute(std::size_t pin)
{
    return getLink(pin);
}

/*
 * For more details see:
 * https://en.wikipedia.org/wiki/Flip-flop_(electronics)#Classical_positive-edge-triggered_D_flip-flop
 */
nts::DFlipFlopComponent::DFlipFlopComponent()
{
    _validPins = {InClk, InData, InRst, InSet, OutNQ, OutQ};
    _outputPins = {OutNQ, OutQ};

    nand3GateA.setLink(Nand3Component::InputA, *this, InSet);
    nand3GateA.setLink(Nand3Component::InputB, nand3GateD, Nand3Component::Output);
    nand3GateA.setLink(Nand3Component::InputC, nand3GateB, Nand3Component::Output);

    nand3GateB.setLink(Nand3Component::InputA, nand3GateA, Nand3Component::Output);
    nand3GateB.setLink(Nand3Component::InputB, *this, InClk);
    nand3GateB.setLink(Nand3Component::InputC, *this, InRst);

    nand3GateC.setLink(Nand3Component::InputA, nand3GateB, Nand3Component::Output);
    nand3GateC.setLink(Nand3Component::InputB, *this, InClk);
    nand3GateC.setLink(Nand3Component::InputC, nand3GateD, Nand3Component::Output);

    nand3GateD.setLink(Nand3Component::InputA, nand3GateC, Nand3Component::Output);
    nand3GateD.setLink(Nand3Component::InputB, *this, InData);
    nand3GateD.setLink(Nand3Component::InputC, *this, InRst);

    nand3GateOutA.setLink(Nand3Component::InputA, *this, InSet);
    nand3GateOutA.setLink(Nand3Component::InputB, nand3GateB, Nand3Component::Output);
    nand3GateOutA.setLink(Nand3Component::InputC, nand3GateOutB, Nand3Component::Output);

    nand3GateOutB.setLink(Nand3Component::InputA, nand3GateOutA, Nand3Component::Output);
    nand3GateOutB.setLink(Nand3Component::InputB, nand3GateC, Nand3Component::Output);
    nand3GateOutB.setLink(Nand3Component::InputC, *this, InRst);

    this->setLink(OutQ, nand3GateOutA, Nand3Component::Output);
    this->setLink(OutNQ, nand3GateOutB, Nand3Component::Output);
}
