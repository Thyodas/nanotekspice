/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** IComponent.hpp
*/

#pragma once

#include <cstddef>
#include <iostream>

namespace nts {
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    class IComponent {
        public :
            virtual ~IComponent() = default;

            virtual void simulate(std::size_t tick) = 0;

            virtual nts::Tristate compute(std::size_t pin) = 0;

            virtual void setLink(std::size_t pin, nts::IComponent &other,
                                 std::size_t otherPin) = 0;
    };
}

static std::ostream &operator<<(std::ostream &stream,
                                const nts::Tristate &state)
{
    switch (state) {
        case nts::Tristate::True:
            return stream << "1";
        case nts::Tristate::False:
            return stream << "0";
        case nts::Tristate::Undefined:
            return stream << "U";
    }
}
