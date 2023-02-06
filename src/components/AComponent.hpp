/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** AComponent.hpp
*/

#pragma once

#include "IComponent.hpp"

#include <map>

namespace nts {
    typedef std::map<std::size_t, std::pair<std::size_t, nts::IComponent *>>
            LinkMap_t;

    class AComponent : public nts::IComponent {
        public:
            AComponent();
            ~AComponent() override = default;

            void simulate(std::size_t tick) override;
            Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, IComponent &other,
                         std::size_t otherPin) override;

        protected:
             LinkMap_t _linkMap;
             std::size_t _tick;
    };
}
