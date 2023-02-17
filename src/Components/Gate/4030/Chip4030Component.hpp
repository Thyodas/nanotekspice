/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Chip4030Component.hpp
*/

#pragma once

#include "../../AComponent.hpp"
#include "../../Elementary/Xor/XorComponent.hpp"

namespace nts {
    class Chip4030Component : public AComponent {
        public:
            enum Pin {
                Input1A = 1,
                Input1B = 2,
                Output1Y = 3,

                Input2A = 5,
                Input2B = 6,
                Output2Y = 4,

                Input3A = 8,
                Input3B = 9,
                Output3Y = 10,

                Input4A = 12,
                Input4B = 13,
                Output4Y = 11,
            };

            Chip4030Component();

            Tristate recompute(std::size_t pin) override;
        private:
            XorComponent xorGate1;
            XorComponent xorGate2;
            XorComponent xorGate3;
            XorComponent xorGate4;
    };
} // nts
