/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** XorComponent.hpp
*/

#pragma once

#include "../AComponent.hpp"
#include "../Not/NotComponent.hpp"
#include "../And/AndComponent.hpp"
#include "../Or/OrComponent.hpp"

namespace nts {
    class XorComponent : public AComponent {
        public:
            enum Pin {
                InputA = 1,
                InputB = 2,
                Output = 3,
            };

            XorComponent();

            Tristate compute(std::size_t pin) override;
        private:
            nts::OrComponent orGate;
            nts::AndComponent andGateA;
            nts::AndComponent andGateB;
            nts::NotComponent notGateA;
            nts::NotComponent notGateB;
    };
} // nts
