/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** AComponent.hpp
*/

#pragma once

#include "IComponent.hpp"

#include <unordered_map>

namespace nts {
    typedef std::unordered_map<std::size_t, std::pair<std::size_t, nts::IComponent *>>
            LinkMap_t;

    class AComponent : public nts::IComponent {
        public:
            AComponent();
            ~AComponent() override = default;

            Tristate compute(std::size_t pin) override final;
            virtual void simulate(std::size_t tick) override;
            void setLink(std::size_t pin, IComponent &other,
                         std::size_t otherPin) override final;
            virtual void setValue(nts::Tristate value) override;
        protected:
            bool isValidPin(std::size_t pin) const;
            Tristate getLink(std::size_t pin);
            LinkMap_t _linkMap;
            std::size_t _tick;
            std::unordered_set<std::size_t> _validPins;
            std::unordered_set<std::size_t> _outputPins;
        private:
            std::unordered_map<std::size_t, nts::Tristate> _computeCacheMap;
            std::unordered_map<std::size_t, nts::Tristate> _prevComputeCacheMap;
            static std::unordered_set<IComponent *> _ringList;
            static std::unordered_set<IComponent *> _ringCheckedList;
            void resetCache(void) override;
            void findRing(IComponent *ringStart,
                          std::unordered_set<IComponent *> pathHistory) override;
    };
}
