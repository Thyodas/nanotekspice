/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** TrueComponent.hpp
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class TrueComponent : public AComponent {
        public:
            TrueComponent();

            Tristate compute(std::size_t pin) override;
    };
} // nts
