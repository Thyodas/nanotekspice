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

            void simulate(std::size_t tick) override;

            Tristate recompute(std::size_t pin) override;
        private:
            Tristate _clock;
            Tristate _prevClock;
            uint16_t _count;
    };
} // nts
