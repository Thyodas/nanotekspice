/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** NandComponent.hpp
*/

#pragma once

#include "../../AComponent.hpp"
#include "../Not/NotComponent.hpp"
#include "../And/AndComponent.hpp"

namespace nts {
    class NandComponent : public AComponent {
        public:
            enum Pin {
                InputA = 1,
                InputB = 2,
                Output = 3,
            };

            NandComponent();

            Tristate recompute(std::size_t pin) override;
        private:
            nts::AndComponent andGate;
            nts::NotComponent notGate;
    };
} // nts
