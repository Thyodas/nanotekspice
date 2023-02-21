/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Chip4040Component.hpp
*/

#pragma once

#include "../../AComponent.hpp"
#include "../JKFlipFlop/JKFlipFlopComponent.hpp"
#include "../../Special/False/FalseComponent.hpp"
#include "../../Elementary/Nor/NorComponent.hpp"

namespace nts {
    class Chip4040Component : public AComponent {
        public:
            enum Pin {
                Q12 = 1,
                Q6 = 2,
                Q5 = 3,
                Q7 = 4,
                Q4 = 5,
                Q3 = 6,
                Q2 = 7,
                Q11 = 15,
                Q10 = 14,
                Q8 = 13,
                Q9 = 12,
                R = 11,
                C = 10,
                Q1 = 9,
            };

            Chip4040Component();

            Tristate recompute(std::size_t pin) override;
        private:
            NotComponent notGateClk;
            OrComponent orGateClk;

            NotComponent notGateFF1;
            NotComponent notGateFF2;
            NotComponent notGateFF3;
            NotComponent notGateFF4;
            NotComponent notGateFF5;
            NotComponent notGateFF6;
            NotComponent notGateFF7;
            NotComponent notGateFF8;
            NotComponent notGateFF9;
            NotComponent notGateFF10;
            NotComponent notGateFF11;

            JKFlipFlopComponent flipFlop1;
            JKFlipFlopComponent flipFlop2;
            JKFlipFlopComponent flipFlop3;
            JKFlipFlopComponent flipFlop4;
            JKFlipFlopComponent flipFlop5;
            JKFlipFlopComponent flipFlop6;
            JKFlipFlopComponent flipFlop7;
            JKFlipFlopComponent flipFlop8;
            JKFlipFlopComponent flipFlop9;
            JKFlipFlopComponent flipFlop10;
            JKFlipFlopComponent flipFlop11;
            JKFlipFlopComponent flipFlop12;
    };
} // nts
