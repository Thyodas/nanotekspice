/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-guillaume.hein
** File description:
** Chip4514Component.hpp
*/

#pragma once

#include "../../AComponent.hpp"
#include "../../Elementary/Not/NotComponent.hpp"
#include "../../Elementary/And/AndComponent.hpp"
#include "../../Elementary/Nand3/Nand3Component.hpp"
#include "../SRFlipFlop/SRFlipFlopComponent.hpp"

namespace nts {
    class Chip4514Component : public AComponent {
        public:
            enum Pin {
                InputA = 2,
                InputB = 3,
                InputC = 21,
                InputD = 22,

                Strobe = 1,
                Inhibit = 23,

                S0 = 11,
                S1 = 9,
                S2 = 10,
                S3 = 8,
                S4 = 7,
                S5 = 6,
                S6 = 5,
                S7 = 4,
                S8 = 18,
                S9 = 17,
                S10 = 20,
                S11 = 19,
                S12 = 14,
                S13 = 13,
                S14 = 16,
                S15 = 15,
            };

            Chip4514Component();

            Tristate recompute(std::size_t pin) override;
        private:
            NotComponent notGateA;
            NotComponent notGateB;
            NotComponent notGateC;
            NotComponent notGateD;

            NotComponent notGateStrobe;
            NotComponent notGateInhibit;

            AndComponent andGateA;
            AndComponent andGateB;
            AndComponent andGateC;
            AndComponent andGateD;

            AndComponent andGateAS;
            AndComponent andGateBS;
            AndComponent andGateCS;
            AndComponent andGateDS;

            SRFlipFlopComponent SRFlipFlopA;
            SRFlipFlopComponent SRFlipFlopB;
            SRFlipFlopComponent SRFlipFlopC;
            SRFlipFlopComponent SRFlipFlopD;

            AndComponent andGateAB;
            AndComponent andGateNAB;
            AndComponent andGateANB;
            AndComponent andGateNANB;
            AndComponent andGateCD;
            AndComponent andGateNCD;
            AndComponent andGateCND;
            AndComponent andGateNCND;

            Nand3Component nandGateS0;
            Nand3Component nandGateS1;
            Nand3Component nandGateS2;
            Nand3Component nandGateS3;
            Nand3Component nandGateS4;
            Nand3Component nandGateS5;
            Nand3Component nandGateS6;
            Nand3Component nandGateS7;
            Nand3Component nandGateS8;
            Nand3Component nandGateS9;
            Nand3Component nandGateS10;
            Nand3Component nandGateS11;
            Nand3Component nandGateS12;
            Nand3Component nandGateS13;
            Nand3Component nandGateS14;
            Nand3Component nandGateS15;

            NotComponent notGateS0;
            NotComponent notGateS1;
            NotComponent notGateS2;
            NotComponent notGateS3;
            NotComponent notGateS4;
            NotComponent notGateS5;
            NotComponent notGateS6;
            NotComponent notGateS7;
            NotComponent notGateS8;
            NotComponent notGateS9;
            NotComponent notGateS10;
            NotComponent notGateS11;
            NotComponent notGateS12;
            NotComponent notGateS13;
            NotComponent notGateS14;
            NotComponent notGateS15;
    };
}