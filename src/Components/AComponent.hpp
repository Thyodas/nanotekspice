/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** AComponent.hpp
*/

#pragma once

#include "IComponent.hpp"

#include <unordered_set>
#include <map>

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
            virtual void setValue(nts::Tristate value) override;
        protected:
            bool isValidPin(std::size_t pin) const;
            Tristate getLink(std::size_t pin);
            LinkMap_t _linkMap;
            std::size_t _tick;
            std::unordered_set<std::size_t> _validPins;
            std::unordered_set<std::size_t> _outputPins;
        private:
            std::map<std::size_t, nts::Tristate> _computeCacheMap;
            void resetCache(void) override;
    };
}
