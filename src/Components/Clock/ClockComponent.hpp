/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** ClockComponent.hpp
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class ClockComponent : public AComponent {
        public:
            enum IO {
                Output = 1,
            };

            ClockComponent();

            void simulate(std::size_t tick) override;

            Tristate compute(std::size_t pin) override;
        private:
            Tristate _value;
    };
}
