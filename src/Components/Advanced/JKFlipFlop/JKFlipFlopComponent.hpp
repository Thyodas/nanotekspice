/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** JKFlipFlopComponent.hpp
*/

#pragma once

#include "../../AComponent.hpp"
#include "../../Elementary/Or/OrComponent.hpp"
#include "../../Elementary/Nand3/Nand3Component.hpp"
#include "../../Elementary/Nor/NorComponent.hpp"
#include "../../Elementary/And3/And3Component.hpp"
#include "../../Special/False/FalseComponent.hpp"
#include "../../Advanced/DFlipFlop/DFlipFlopComponent.hpp"

namespace nts {
    class JKFlipFlopComponent : public AComponent {
        public:
            enum Pin {
                InJ = 1,
                InClk = 2,
                InK = 3,
                InRst = 4,
                OutQ = 5,
                OutNQ = 6,
            };

            JKFlipFlopComponent();

            Tristate recompute(std::size_t pin) override;
        private:
            nts::NotComponent notGateK;
            nts::AndComponent andGateJ;
            nts::AndComponent andGateK;

            nts::OrComponent orGate;

            nts::FalseComponent falseGate;

            nts::DFlipFlopComponent flipFlop;
            nts::Tristate _value;
            nts::Tristate _prevClock;
    };
} // nts
