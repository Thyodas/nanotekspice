/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Chip4008Component.hpp
*/

#pragma once

#include "../../AComponent.hpp"
#include "../Adder/AdderComponent.hpp"

namespace nts {
    class Chip4008Component : public AComponent {
        public:
            enum Pin {
                InA4 = 1,
                InB3 = 2,
                InA3 = 3,
                InB2 = 4,
                InA2 = 5,
                InB1 = 6,
                InA1 = 7,
                InC1 = 9,
                OutS1 = 10,
                OutS2 = 11,
                OutS3 = 12,
                OutS4 = 13,
                OutCO = 14,
                InB4 = 15,
            };

            Chip4008Component();

            Tristate recompute(std::size_t pin) override;
        private:
            nts::AdderComponent adder1;
            nts::AdderComponent adder2;
            nts::AdderComponent adder3;
            nts::AdderComponent adder4;
    };
} // nts
