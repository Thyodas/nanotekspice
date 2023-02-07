/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** OutputComponent.hpp
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class OutputComponent : public AComponent {
        public:
            OutputComponent();

            Tristate compute(std::size_t pin) override;
    };
}
