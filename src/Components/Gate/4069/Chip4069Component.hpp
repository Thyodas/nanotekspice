/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Chip4069Component.hpp
*/

#pragma once

#include "../../AComponent.hpp"
#include "../../Elementary/Not/NotComponent.hpp"

namespace nts {
    class Chip4069Component : public AComponent {
        public:
            enum Pin {
                Input1 = 1, Output1 = 2,
                Input2 = 3, Output2 = 4,
                Input3 = 5, Output3 = 6,
                Input4 = 9, Output4 = 8,
                Input5 = 11, Output5 = 10,
                Input6 = 13, Output6 = 12,
            };

            Chip4069Component();

            Tristate recompute(std::size_t pin) override;
        private:
            NotComponent notGate1;
            NotComponent notGate2;
            NotComponent notGate3;
            NotComponent notGate4;
            NotComponent notGate5;
            NotComponent notGate6;
    };
} // nts
