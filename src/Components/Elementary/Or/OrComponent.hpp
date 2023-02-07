/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** OrComponent.hpp
*/

#pragma once

#include "../../AComponent.hpp"

namespace nts {
    class OrComponent : public AComponent {
        public:
            enum Pin {
                InputA = 1,
                InputB = 2,
                Output = 3,
            };
            OrComponent();

            Tristate compute(std::size_t pin) override;
    };
} // nts
