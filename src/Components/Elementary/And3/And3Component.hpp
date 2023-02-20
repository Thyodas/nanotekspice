/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** And3Component.hpp
*/

#pragma once

#include "../../AComponent.hpp"
#include "../Not/NotComponent.hpp"
#include "../And/AndComponent.hpp"

namespace nts {
    class And3Component : public AComponent {
        public:
            enum Pin {
                InputA = 1,
                InputB = 2,
                InputC = 3,
                Output = 4,
            };

            And3Component();

            Tristate recompute(std::size_t pin) override;
        private:
            nts::AndComponent andGateA;
            nts::AndComponent andGateB;
    };
} // nts
