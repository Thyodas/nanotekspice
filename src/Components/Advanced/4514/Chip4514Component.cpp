/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-guillaume.hein
** File description:
** Chip4514Component.cpp
*/

#include "Chip4514Component.hpp"

nts::Tristate nts::Chip4514Component::recompute(std::size_t pin)
{
    return getLink(pin);
}

nts::Chip4514Component::Chip4514Component()
{
    _validPins = {InputA, InputB, InputC, InputD, Strobe, Inhibit,
                  S0, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, S11, S12, S13, S14, S15};
    _outputPins = {S0, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, S11, S12, S13, S14, S15};

    notGateA.setLink(NotComponent::Input, *this, InputA);
    notGateB.setLink(NotComponent::Input, *this, InputB);
    notGateC.setLink(NotComponent::Input, *this, InputC);
    notGateD.setLink(NotComponent::Input, *this, InputD);

    notGateStrobe.setLink(NotComponent::Input, *this, Strobe);
    notGateInhibit.setLink(NotComponent::Input, *this, Inhibit);

    andGateA.setLink(AndComponent::InputA, notGateA, NotComponent::Output);
    andGateA.setLink(AndComponent::InputB, notGateStrobe, NotComponent::Output);
    andGateB.setLink(AndComponent::InputA, notGateB, NotComponent::Output);
    andGateB.setLink(AndComponent::InputB, notGateStrobe, NotComponent::Output);
    andGateC.setLink(AndComponent::InputA, notGateC, NotComponent::Output);
    andGateC.setLink(AndComponent::InputB, notGateStrobe, NotComponent::Output);
    andGateD.setLink(AndComponent::InputA, notGateD, NotComponent::Output);
    andGateD.setLink(AndComponent::InputB, notGateStrobe, NotComponent::Output);

    andGateAS.setLink(AndComponent::InputA, andGateA, AndComponent::Output);
    andGateAS.setLink(AndComponent::InputB, notGateStrobe, NotComponent::Output);
    andGateBS.setLink(AndComponent::InputA, andGateB, AndComponent::Output);
    andGateBS.setLink(AndComponent::InputB, notGateStrobe, NotComponent::Output);
    andGateCS.setLink(AndComponent::InputA, andGateC, AndComponent::Output);
    andGateCS.setLink(AndComponent::InputB, notGateStrobe, NotComponent::Output);
    andGateDS.setLink(AndComponent::InputA, andGateD, AndComponent::Output);
    andGateDS.setLink(AndComponent::InputB, notGateStrobe, NotComponent::Output);

    SRFlipFlopA.setLink(SRFlipFlopComponent::InSet, andGateA, AndComponent::Output);
    SRFlipFlopA.setLink(SRFlipFlopComponent::InRst, andGateAS, AndComponent::Output);
    SRFlipFlopB.setLink(SRFlipFlopComponent::InSet, andGateB, AndComponent::Output);
    SRFlipFlopB.setLink(SRFlipFlopComponent::InRst, andGateBS, AndComponent::Output);
    SRFlipFlopC.setLink(SRFlipFlopComponent::InSet, andGateC, AndComponent::Output);
    SRFlipFlopC.setLink(SRFlipFlopComponent::InRst, andGateCS, AndComponent::Output);
    SRFlipFlopD.setLink(SRFlipFlopComponent::InSet, andGateD, AndComponent::Output);
    SRFlipFlopD.setLink(SRFlipFlopComponent::InRst, andGateDS, AndComponent::Output);

    andGateAB.setLink(AndComponent::InputA, SRFlipFlopA, SRFlipFlopComponent::OutQ);
    andGateAB.setLink(AndComponent::InputB, SRFlipFlopB, SRFlipFlopComponent::OutQ);
    andGateNAB.setLink(AndComponent::InputA, SRFlipFlopA, SRFlipFlopComponent::OutNQ);
    andGateNAB.setLink(AndComponent::InputB, SRFlipFlopB, SRFlipFlopComponent::OutQ);
    andGateANB.setLink(AndComponent::InputA, SRFlipFlopA, SRFlipFlopComponent::OutQ);
    andGateANB.setLink(AndComponent::InputB, SRFlipFlopB, SRFlipFlopComponent::OutNQ);
    andGateNANB.setLink(AndComponent::InputA, SRFlipFlopA, SRFlipFlopComponent::OutNQ);
    andGateNANB.setLink(AndComponent::InputB, SRFlipFlopB, SRFlipFlopComponent::OutNQ);
    andGateCD.setLink(AndComponent::InputA, SRFlipFlopC, SRFlipFlopComponent::OutQ);
    andGateCD.setLink(AndComponent::InputB, SRFlipFlopD, SRFlipFlopComponent::OutQ);
    andGateNCD.setLink(AndComponent::InputA, SRFlipFlopC, SRFlipFlopComponent::OutNQ);
    andGateNCD.setLink(AndComponent::InputB, SRFlipFlopD, SRFlipFlopComponent::OutQ);
    andGateCND.setLink(AndComponent::InputA, SRFlipFlopC, SRFlipFlopComponent::OutQ);
    andGateCND.setLink(AndComponent::InputB, SRFlipFlopD, SRFlipFlopComponent::OutNQ);
    andGateNCND.setLink(AndComponent::InputA, SRFlipFlopC, SRFlipFlopComponent::OutNQ);
    andGateNCND.setLink(AndComponent::InputB, SRFlipFlopD, SRFlipFlopComponent::OutNQ);

    nandGateS0.setLink(Nand3Component::InputA, andGateCD, AndComponent::Output);
    nandGateS0.setLink(Nand3Component::InputB, andGateAB, AndComponent::Output);
    nandGateS0.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    nandGateS1.setLink(Nand3Component::InputA, andGateCD, AndComponent::Output);
    nandGateS1.setLink(Nand3Component::InputB, andGateNAB, AndComponent::Output);
    nandGateS1.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    nandGateS2.setLink(Nand3Component::InputA, andGateCD, AndComponent::Output);
    nandGateS2.setLink(Nand3Component::InputB, andGateANB, AndComponent::Output);
    nandGateS2.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    nandGateS3.setLink(Nand3Component::InputA, andGateCD, AndComponent::Output);
    nandGateS3.setLink(Nand3Component::InputB, andGateNANB, AndComponent::Output);
    nandGateS3.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    nandGateS4.setLink(Nand3Component::InputA, andGateNCD, AndComponent::Output);
    nandGateS4.setLink(Nand3Component::InputB, andGateAB, AndComponent::Output);
    nandGateS4.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    nandGateS5.setLink(Nand3Component::InputA, andGateNCD, AndComponent::Output);
    nandGateS5.setLink(Nand3Component::InputB, andGateNAB, AndComponent::Output);
    nandGateS5.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    nandGateS6.setLink(Nand3Component::InputA, andGateNCD, AndComponent::Output);
    nandGateS6.setLink(Nand3Component::InputB, andGateANB, AndComponent::Output);
    nandGateS6.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    nandGateS7.setLink(Nand3Component::InputA, andGateNCD, AndComponent::Output);
    nandGateS7.setLink(Nand3Component::InputB, andGateNANB, AndComponent::Output);
    nandGateS7.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    nandGateS8.setLink(Nand3Component::InputA, andGateCND, AndComponent::Output);
    nandGateS8.setLink(Nand3Component::InputB, andGateAB, AndComponent::Output);
    nandGateS8.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    nandGateS9.setLink(Nand3Component::InputA, andGateCND, AndComponent::Output);
    nandGateS9.setLink(Nand3Component::InputB, andGateNAB, AndComponent::Output);
    nandGateS9.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    nandGateS10.setLink(Nand3Component::InputA, andGateCND, AndComponent::Output);
    nandGateS10.setLink(Nand3Component::InputB, andGateANB, AndComponent::Output);
    nandGateS10.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    nandGateS11.setLink(Nand3Component::InputA, andGateCND, AndComponent::Output);
    nandGateS11.setLink(Nand3Component::InputB, andGateNANB, AndComponent::Output);
    nandGateS11.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    nandGateS12.setLink(Nand3Component::InputA, andGateNCND, AndComponent::Output);
    nandGateS12.setLink(Nand3Component::InputB, andGateAB, AndComponent::Output);
    nandGateS12.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    nandGateS13.setLink(Nand3Component::InputA, andGateNCND, AndComponent::Output);
    nandGateS13.setLink(Nand3Component::InputB, andGateNAB, AndComponent::Output);
    nandGateS13.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    nandGateS14.setLink(Nand3Component::InputA, andGateNCND, AndComponent::Output);
    nandGateS14.setLink(Nand3Component::InputB, andGateANB, AndComponent::Output);
    nandGateS14.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    nandGateS15.setLink(Nand3Component::InputA, andGateNCND, AndComponent::Output);
    nandGateS15.setLink(Nand3Component::InputB, andGateNANB, AndComponent::Output);
    nandGateS15.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);

    notGateS0.setLink(NotComponent::Input, nandGateS0, Nand3Component::Output);
    notGateS1.setLink(NotComponent::Input, nandGateS1, Nand3Component::Output);
    notGateS2.setLink(NotComponent::Input, nandGateS2, Nand3Component::Output);
    notGateS3.setLink(NotComponent::Input, nandGateS3, Nand3Component::Output);
    notGateS4.setLink(NotComponent::Input, nandGateS4, Nand3Component::Output);
    notGateS5.setLink(NotComponent::Input, nandGateS5, Nand3Component::Output);
    notGateS6.setLink(NotComponent::Input, nandGateS6, Nand3Component::Output);
    notGateS7.setLink(NotComponent::Input, nandGateS7, Nand3Component::Output);
    notGateS8.setLink(NotComponent::Input, nandGateS8, Nand3Component::Output);
    notGateS9.setLink(NotComponent::Input, nandGateS9, Nand3Component::Output);
    notGateS10.setLink(NotComponent::Input, nandGateS10, Nand3Component::Output);
    notGateS11.setLink(NotComponent::Input, nandGateS11, Nand3Component::Output);
    notGateS12.setLink(NotComponent::Input, nandGateS12, Nand3Component::Output);
    notGateS13.setLink(NotComponent::Input, nandGateS13, Nand3Component::Output);
    notGateS14.setLink(NotComponent::Input, nandGateS14, Nand3Component::Output);
    notGateS15.setLink(NotComponent::Input, nandGateS15, Nand3Component::Output);

    this->setLink(S0, notGateS0, NotComponent::Output);
    this->setLink(S1, notGateS1, NotComponent::Output);
    this->setLink(S2, notGateS2, NotComponent::Output);
    this->setLink(S3, notGateS3, NotComponent::Output);
    this->setLink(S4, notGateS4, NotComponent::Output);
    this->setLink(S5, notGateS5, NotComponent::Output);
    this->setLink(S6, notGateS6, NotComponent::Output);
    this->setLink(S7, notGateS7, NotComponent::Output);
    this->setLink(S8, notGateS8, NotComponent::Output);
    this->setLink(S9, notGateS9, NotComponent::Output);
    this->setLink(S10, notGateS10, NotComponent::Output);
    this->setLink(S11, notGateS11, NotComponent::Output);
    this->setLink(S12, notGateS12, NotComponent::Output);
    this->setLink(S13, notGateS13, NotComponent::Output);
    this->setLink(S14, notGateS14, NotComponent::Output);
    this->setLink(S15, notGateS15, NotComponent::Output);
}