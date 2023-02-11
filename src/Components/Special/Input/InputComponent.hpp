/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** InputComponent.hpp
*/

#pragma once

#include "../../AComponent.hpp"

namespace nts {
    class InputComponent : public AComponent {
        public:
            enum Pin {
                Output = 1,
            };

            InputComponent();

            void simulate(std::size_t tick) override;
            void setValue(nts::Tristate value) override;

            Tristate compute(std::size_t pin) override;
        private:
            Tristate _value;
            Tristate _newValue;
    };
}
