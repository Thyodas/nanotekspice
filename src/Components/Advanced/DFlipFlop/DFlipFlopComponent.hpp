/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** DFlipFlopComponent.hpp
*/

#pragma once

#include "../../AComponent.hpp"
#include "../../Elementary/Or/OrComponent.hpp"
#include "../../Elementary/Nand3/Nand3Component.hpp"

namespace nts {
    class DFlipFlopComponent : public AComponent {
        public:
            enum Pin {
                InSet = 1,
                InData = 2,
                InRst = 3,
                InClk = 4,
                OutNQ = 5,
                OutQ = 6,
            };

            DFlipFlopComponent();

            Tristate compute(std::size_t pin) override;
        private:
            nts::Nand3Component nand3GateA;
            nts::Nand3Component nand3GateB;
            nts::Nand3Component nand3GateC;
            nts::Nand3Component nand3GateD;

            nts::Nand3Component nand3GateOutA;
            nts::Nand3Component nand3GateOutB;
    };
} // nts
