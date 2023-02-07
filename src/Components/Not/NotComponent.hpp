/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** NotComponent.hpp
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class NotComponent : public AComponent {
        public:
            NotComponent();

            Tristate compute(std::size_t pin) override;
    };
} // nts
