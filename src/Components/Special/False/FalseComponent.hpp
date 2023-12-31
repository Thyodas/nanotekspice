/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** FalseComponent.hpp
*/

#pragma once

#include "../../AComponent.hpp"

namespace nts {
    class FalseComponent : public AComponent {
        public:
            enum Pin {
                Output = 1,
            };
            FalseComponent();

            Tristate recompute(std::size_t pin) override;
    };
} // nts
