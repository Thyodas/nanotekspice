/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** HalfAdderComponent.hpp
*/

#pragma once

#include "../../AComponent.hpp"
#include "../../Elementary/And/AndComponent.hpp"
#include "../../Elementary/Xor/XorComponent.hpp"

namespace nts {
    class HalfAdderComponent : public AComponent {
        public:
            enum Pin {
                InputA = 1,
                InputB = 2,
                SumOutput = 3,
                CarryOutput = 4,
            };

            HalfAdderComponent();

            Tristate compute(std::size_t pin) override;
        private:
            nts::XorComponent xorGate;
            nts::AndComponent andGate;
    };
} // nts
