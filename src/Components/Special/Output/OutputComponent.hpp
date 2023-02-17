/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** OutputComponent.hpp
*/

#pragma once

#include "../../AComponent.hpp"

namespace nts {
    class OutputComponent : public AComponent {
        public:
            enum Pin {
                Input = 1,
            };
            OutputComponent();

            Tristate recompute(std::size_t pin) override;
    };
}
