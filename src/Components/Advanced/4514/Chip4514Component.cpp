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

    notGateInhibit.setLink(NotComponent::Input, *this, Inhibit);

    andGateA.setLink(AndComponent::InputA, *this, InputA);
    andGateA.setLink(AndComponent::InputB, *this, Strobe);
    andGateB.setLink(AndComponent::InputA, *this, InputB);
    andGateB.setLink(AndComponent::InputB, *this, Strobe);
    andGateC.setLink(AndComponent::InputA, *this, InputC);
    andGateC.setLink(AndComponent::InputB, *this, Strobe);
    andGateD.setLink(AndComponent::InputA, *this, InputD);
    andGateD.setLink(AndComponent::InputB, *this, Strobe);

    notGateA.setLink(NotComponent::Input, andGateA, AndComponent::Output);
    notGateB.setLink(NotComponent::Input, andGateB, AndComponent::Output);
    notGateC.setLink(NotComponent::Input, andGateC, AndComponent::Output);
    notGateD.setLink(NotComponent::Input, andGateD, AndComponent::Output);

    andGateAS.setLink(AndComponent::InputA, notGateA, NotComponent::Output);
    andGateAS.setLink(AndComponent::InputB, *this, Strobe);
    andGateBS.setLink(AndComponent::InputA, notGateB, NotComponent::Output);
    andGateBS.setLink(AndComponent::InputB, *this, Strobe);
    andGateCS.setLink(AndComponent::InputA, notGateC, NotComponent::Output);
    andGateCS.setLink(AndComponent::InputB, *this, Strobe);
    andGateDS.setLink(AndComponent::InputA, notGateD, NotComponent::Output);
    andGateDS.setLink(AndComponent::InputB, *this, Strobe);

    SRFlipFlopA.setLink(SRFlipFlopComponent::InSet, andGateA, AndComponent::Output);
    SRFlipFlopA.setLink(SRFlipFlopComponent::InRst, andGateAS, AndComponent::Output);
    SRFlipFlopB.setLink(SRFlipFlopComponent::InSet, andGateB, AndComponent::Output);
    SRFlipFlopB.setLink(SRFlipFlopComponent::InRst, andGateBS, AndComponent::Output);
    SRFlipFlopC.setLink(SRFlipFlopComponent::InSet, andGateC, AndComponent::Output);
    SRFlipFlopC.setLink(SRFlipFlopComponent::InRst, andGateCS, AndComponent::Output);
    SRFlipFlopD.setLink(SRFlipFlopComponent::InSet, andGateD, AndComponent::Output);
    SRFlipFlopD.setLink(SRFlipFlopComponent::InRst, andGateDS, AndComponent::Output);

    andGateA2.setLink(AndComponent::InputA, SRFlipFlopA, SRFlipFlopComponent::OutNQ);
    andGateA2.setLink(AndComponent::InputB, SRFlipFlopB, SRFlipFlopComponent::OutNQ);
    andGateB2.setLink(AndComponent::InputA, SRFlipFlopA, SRFlipFlopComponent::OutQ);
    andGateB2.setLink(AndComponent::InputB, SRFlipFlopB, SRFlipFlopComponent::OutNQ);
    andGateC2.setLink(AndComponent::InputA, SRFlipFlopA, SRFlipFlopComponent::OutNQ);
    andGateC2.setLink(AndComponent::InputB, SRFlipFlopB, SRFlipFlopComponent::OutQ);
    andGateD2.setLink(AndComponent::InputA, SRFlipFlopA, SRFlipFlopComponent::OutQ);
    andGateD2.setLink(AndComponent::InputB, SRFlipFlopB, SRFlipFlopComponent::OutQ);
    andGateE2.setLink(AndComponent::InputA, SRFlipFlopC, SRFlipFlopComponent::OutNQ);
    andGateE2.setLink(AndComponent::InputB, SRFlipFlopD, SRFlipFlopComponent::OutNQ);
    andGateF2.setLink(AndComponent::InputA, SRFlipFlopC, SRFlipFlopComponent::OutQ);
    andGateF2.setLink(AndComponent::InputB, SRFlipFlopD, SRFlipFlopComponent::OutNQ);
    andGateG2.setLink(AndComponent::InputA, SRFlipFlopC, SRFlipFlopComponent::OutNQ);
    andGateG2.setLink(AndComponent::InputB, SRFlipFlopD, SRFlipFlopComponent::OutQ);
    andGateH2.setLink(AndComponent::InputA, SRFlipFlopC, SRFlipFlopComponent::OutQ);
    andGateH2.setLink(AndComponent::InputB, SRFlipFlopD, SRFlipFlopComponent::OutQ);

    nandGateS0.setLink(Nand3Component::InputA, andGateE2, AndComponent::Output);
    nandGateS0.setLink(Nand3Component::InputB, andGateA2, AndComponent::Output);
    nandGateS0.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);

    nandGateS1.setLink(Nand3Component::InputA, andGateE2, AndComponent::Output);
    nandGateS1.setLink(Nand3Component::InputB, andGateB2, AndComponent::Output);
    nandGateS1.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);

    nandGateS2.setLink(Nand3Component::InputA, andGateE2, AndComponent::Output);
    nandGateS2.setLink(Nand3Component::InputB, andGateC2, AndComponent::Output);
    nandGateS2.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);

    nandGateS3.setLink(Nand3Component::InputA, andGateE2, AndComponent::Output);
    nandGateS3.setLink(Nand3Component::InputB, andGateD2, AndComponent::Output);
    nandGateS3.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);

    nandGateS4.setLink(Nand3Component::InputA, andGateF2, AndComponent::Output);
    nandGateS4.setLink(Nand3Component::InputB, andGateA2, AndComponent::Output);
    nandGateS4.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);

    nandGateS5.setLink(Nand3Component::InputA, andGateF2, AndComponent::Output);
    nandGateS5.setLink(Nand3Component::InputB, andGateB2, AndComponent::Output);
    nandGateS5.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    
    nandGateS6.setLink(Nand3Component::InputA, andGateF2, AndComponent::Output);
    nandGateS6.setLink(Nand3Component::InputB, andGateC2, AndComponent::Output);
    nandGateS6.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    
    nandGateS7.setLink(Nand3Component::InputA, andGateF2, AndComponent::Output);
    nandGateS7.setLink(Nand3Component::InputB, andGateD2, AndComponent::Output);
    nandGateS7.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    
    nandGateS8.setLink(Nand3Component::InputA, andGateG2, AndComponent::Output);
    nandGateS8.setLink(Nand3Component::InputB, andGateA2, AndComponent::Output);
    nandGateS8.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    
    nandGateS9.setLink(Nand3Component::InputA, andGateG2, AndComponent::Output);
    nandGateS9.setLink(Nand3Component::InputB, andGateB2, AndComponent::Output);
    nandGateS9.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    
    nandGateS10.setLink(Nand3Component::InputA, andGateG2, AndComponent::Output);
    nandGateS10.setLink(Nand3Component::InputB, andGateC2, AndComponent::Output);
    nandGateS10.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    
    nandGateS11.setLink(Nand3Component::InputA, andGateG2, AndComponent::Output);
    nandGateS11.setLink(Nand3Component::InputB, andGateD2, AndComponent::Output);
    nandGateS11.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    
    nandGateS12.setLink(Nand3Component::InputA, andGateH2, AndComponent::Output);
    nandGateS12.setLink(Nand3Component::InputB, andGateA2, AndComponent::Output);
    nandGateS12.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    
    nandGateS13.setLink(Nand3Component::InputA, andGateH2, AndComponent::Output);
    nandGateS13.setLink(Nand3Component::InputB, andGateB2, AndComponent::Output);
    nandGateS13.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    
    nandGateS14.setLink(Nand3Component::InputA, andGateH2, AndComponent::Output);
    nandGateS14.setLink(Nand3Component::InputB, andGateC2, AndComponent::Output);
    nandGateS14.setLink(Nand3Component::InputC, notGateInhibit, NotComponent::Output);
    
    nandGateS15.setLink(Nand3Component::InputA, andGateH2, AndComponent::Output);
    nandGateS15.setLink(Nand3Component::InputB, andGateD2, AndComponent::Output);
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