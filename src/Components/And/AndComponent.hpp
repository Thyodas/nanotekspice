/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** AndComponent.hpp
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class AndComponent : public AComponent {
        public:
            AndComponent();

            Tristate compute(std::size_t pin) override;
    };
} // nts
