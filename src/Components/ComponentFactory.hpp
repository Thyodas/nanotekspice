/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** ComponentFactory.hpp
*/

#pragma once

#include "IComponent.hpp"

#include <string>
#include <functional>
#include <map>
#include <memory>

namespace nts {
    class ComponentFactory {
        public:
            ComponentFactory();
            ~ComponentFactory();

            std::unique_ptr<IComponent> createComponent(const std::string
                                                        &name);
        private:
            void registerComponent(const std::string &name,
              const std::function<std::unique_ptr<IComponent>()> &constructor);

            std::map<std::string, std::function<std::unique_ptr<IComponent>()>>
                _constructorMap;
    };
}
