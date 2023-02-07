/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** NotComponent.hpp
*/

#pragma once

#include "../../AComponent.hpp"

namespace nts {
    class NotComponent : public AComponent {
        public:
            enum Pin {
                Input = 1,
                Output = 2,
            };
            NotComponent();

            Tristate compute(std::size_t pin) override;
    };
} // nts
