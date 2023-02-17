/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** AndComponent.hpp
*/

#pragma once

#include "../../AComponent.hpp"

namespace nts {
    class AndComponent : public AComponent {
        public:
            enum Pin {
                InputA = 1,
                InputB = 2,
                Output = 3,
            };
            AndComponent();

            Tristate recompute(std::size_t pin) override;
    };
} // nts
