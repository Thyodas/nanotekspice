/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Nand3Component.hpp
*/

#pragma once

#include "../../AComponent.hpp"
#include "../Nand/NandComponent.hpp"

// Nand with 3 inputs
namespace nts {
    class Nand3Component : public AComponent {
        public:
            enum Pin {
                InputA = 1,
                InputB = 2,
                InputC = 3,
                Output = 4,
            };

            Nand3Component();

            Tristate compute(std::size_t pin) override;
        private:
            nts::NandComponent nandGateA;
            nts::NandComponent nandGateB;
            nts::NandComponent nandGateC;
    };
} // nts
