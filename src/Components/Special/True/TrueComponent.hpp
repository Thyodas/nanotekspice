/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** TrueComponent.hpp
*/

#pragma once

#include "../../AComponent.hpp"

namespace nts {
    class TrueComponent : public AComponent {
        public:
            enum Pin {
                Output = 1,
            };

            TrueComponent();

            Tristate recompute(std::size_t pin) override;
    };
} // nts
