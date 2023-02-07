/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** NorComponent.hpp
*/

#pragma once

#include "../../AComponent.hpp"
#include "../Not/NotComponent.hpp"
#include "../Or/OrComponent.hpp"

namespace nts {
    class NorComponent : public AComponent {
        public:
            enum Pin {
                InputA = 1,
                InputB = 2,
                Output = 3,
            };

            NorComponent();

            Tristate compute(std::size_t pin) override;
        private:
            nts::OrComponent orGate;
            nts::NotComponent notGate;
    };
} // nts
