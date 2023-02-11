/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Chip4013Component.hpp
*/

#pragma once

#include "../../AComponent.hpp"
#include "../DFlipFlop/DFlipFlopComponent.hpp"

namespace nts {
    class Chip4013Component : public AComponent {
        public:
            enum Pin {
                OutQ1 = 1,
                OutNQ1 = 2,
                InClk1 = 3,
                InRst1 = 4,
                InData1 = 5,
                InSet1 = 6,
                InSet2 = 8,
                InData2 = 9,
                InRst2 = 10,
                InClk2 = 11,
                OutNQ2 = 12,
                OutQ2 = 13,
            };

            Chip4013Component();

            Tristate compute(std::size_t pin) override;
        private:
            DFlipFlopComponent flipFlop1;
            DFlipFlopComponent flipFlop2;
    };
} // nts
