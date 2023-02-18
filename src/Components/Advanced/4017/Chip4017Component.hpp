/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Chip4017Component.hpp
*/

#pragma once

#include "../../AComponent.hpp"
#include "../DFlipFlop/DFlipFlopComponent.hpp"
#include "../../Special/False/FalseComponent.hpp"
#include "../../Elementary/Nor/NorComponent.hpp"

namespace nts {
    class Chip4017Component : public AComponent {
        public:
            enum Pin {
                Q0 = 3,
                Q1 = 2,
                Q2 = 4,
                Q3 = 7,
                Q4 = 10,
                Q5 = 1,
                Q6 = 5,
                Q7 = 6,
                Q8 = 9,
                Q9 = 11,
                QB5_9 = 12,
                CP1 = 13,
                CP0 = 14,
                MR = 15,
            };

            Chip4017Component();

            Tristate recompute(std::size_t pin) override;
        private:
            FalseComponent falseGate;

            NotComponent notGateCP1;

            AndComponent andGateCP;

            OrComponent orGateFF;
            AndComponent andGateFF;

            DFlipFlopComponent flipFlop1;
            DFlipFlopComponent flipFlop2;
            DFlipFlopComponent flipFlop3;
            DFlipFlopComponent flipFlop4;
            DFlipFlopComponent flipFlop5;

            NorComponent norGateQ0;
            NorComponent norGateQ1;
            NorComponent norGateQ2;
            NorComponent norGateQ3;
            NorComponent norGateQ4;
            NorComponent norGateQ5;
            NorComponent norGateQ6;
            NorComponent norGateQ7;
            NorComponent norGateQ8;
            NorComponent norGateQ9;
    };
} // nts
