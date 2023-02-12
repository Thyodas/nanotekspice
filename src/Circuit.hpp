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
            Circuit();
            void addComponent(std::string type, std::string name);
            void simulator();
            static void sigHandler(int signum);
        private:
            void setLoop();
            void loop();
            void display();
            void simulate();
            void exit();
            void setInputValue(std::string name, std::string state);
            std::map<std::string, void (nts::Circuit::*)(void)> _commands;
            std::map<std::string, IComponent *> _components;
            public:
            static bool _loop;
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
