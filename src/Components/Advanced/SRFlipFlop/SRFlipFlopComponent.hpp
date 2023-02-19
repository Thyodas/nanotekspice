/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** SRFlipFlopComponent.hpp
*/

#pragma once

#include "../../AComponent.hpp"
#include "../../Elementary/Or/OrComponent.hpp"
#include "../../Elementary/Nor/NorComponent.hpp"

namespace nts {
    class SRFlipFlopComponent : public AComponent {
        public:
            enum Pin {
                InSet = 1,
                InRst = 2,
                OutNQ = 4,
                OutQ = 5,
            };

            SRFlipFlopComponent();

            Tristate recompute(std::size_t pin) override;
        private:
            nts::NorComponent norGateA;
            nts::NorComponent norGateB;
    };
} // nts
