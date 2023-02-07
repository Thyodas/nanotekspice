/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** FalseComponent.hpp
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class FalseComponent : public AComponent {
        public:
            enum IO {
                Output = 1,
            };
            FalseComponent();

            Tristate compute(std::size_t pin) override;
    };
} // nts
