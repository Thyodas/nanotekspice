/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-guillaume.hein
** File description:
** Circuit.hpp
*/

#pragma once

#include "IComponent.hpp"
#include <map>

namespace nts {
    class Circuit {
        public:
            void addComponent(IComponent* component, std::string name);
        private:
            std::map<std::string, IComponent *> _components;
    };

    class Error : public std::exception {
        public:
            ~Error() = default;
            Error(std::string error);
            const char *what() const noexcept override;
        private:
            std::string _error;
    };
}