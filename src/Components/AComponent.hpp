/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** AComponent.hpp
*/

#pragma once

#include "IComponent.hpp"

#include <map>
#include <unordered_set>

namespace nts {
    typedef std::map<std::size_t, std::pair<std::size_t, nts::IComponent *>>
            LinkMap_t;

    class AComponent : public nts::IComponent {
        public:
            AComponent();
            ~AComponent() override = default;

            virtual void simulate(std::size_t tick) override;
            void setLink(std::size_t pin, IComponent &other,
                         std::size_t otherPin) override;

        protected:
            bool isValidPin(std::size_t pin) const;
            Tristate getLink(std::size_t pin) const;
            LinkMap_t _linkMap;
            std::size_t _tick;
            std::unordered_set<std::size_t> _validPins;
    };
}
