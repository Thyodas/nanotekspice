/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** AdderComponent.hpp
*/

#pragma once

#include "../../AComponent.hpp"
#include "../HalfAdder/HalfAdderComponent.hpp"
#include "../../Elementary/Or/OrComponent.hpp"

namespace nts {
    class AdderComponent : public AComponent {
        public:
            enum Pin {
                InputA = 1,
                InputB = 2,
                CarryInput = 3,
                SumOutput = 4,
                CarryOutput = 5,
            };

            AdderComponent();

            Tristate recompute(std::size_t pin) override;
        private:
            nts::OrComponent orGate;
            nts::HalfAdderComponent halfAdderGateA;
            nts::HalfAdderComponent halfAdderGateB;
    };
} // nts
