/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** InputComponent.hpp
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class InputComponent : public AComponent {
        public:
            InputComponent();

            Tristate compute(std::size_t pin) override;
    };
}
