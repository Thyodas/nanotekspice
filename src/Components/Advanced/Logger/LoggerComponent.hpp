/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** LoggerComponent.hpp
*/

#pragma once

#include "../../AComponent.hpp"
#include "../Adder/AdderComponent.hpp"

#include <fstream>

namespace nts {
    class LoggerComponent : public AComponent {
        public:
            enum Pin {
                In1 = 1,
                In2 = 2,
                In3 = 3,
                In4 = 4,
                In5 = 5,
                In6 = 6,
                In7 = 7,
                In8 = 8,
                InClock = 9,
                InInhibit = 10,
            };

            LoggerComponent();
            ~LoggerComponent();

            void simulate(std::size_t tick) override;
            Tristate compute(std::size_t pin) override;
        private:
            std::ofstream _file;
            bool simulateAllInputs(std::size_t tick);
    };
} // nts
