/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-guillaume.hein
** File description:
** Circuit.hpp
*/

#pragma once

#include "IComponent.hpp"
#include "Components/ComponentFactory.hpp"
#include <map>

namespace nts {
    class Circuit {
        public:
            Circuit();
            void addComponent(std::string type, std::string name, nts::ComponentFactory *factory);
            void setLinks(std::string name1, std::size_t pin1, std::string name2, std::size_t pin2);
            void simulator();

            static void sigHandler(int signum);

            static bool _loop;
        private:
            void setLoop();
            void loop();
            void display();
            void simulate();
            void exit();
            void setInputValue(std::string name, std::string state);

            std::map<std::string, void (nts::Circuit::*)(void)> _commands;
            std::map<std::string, std::unique_ptr<nts::IComponent>> _components;
            std::vector<std::string> _inputs;
            std::vector<std::string> _outputs;
            bool _exit = false;
            std::size_t _ticks;
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
