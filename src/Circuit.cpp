/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-guillaume.hein
** File description:
** Circuit.cpp
*/

#include "Circuit.hpp"
#include "utils/utils.hpp"
#include <utility>
#include <csignal>
#include <vector>
#include <map>

bool nts::Circuit::_loop = false;

nts::Error::Error(std::string error)
: _error(std::move(error))
{
}

nts::Circuit::Circuit()
{
    _commands["loop"] = &nts::Circuit::setLoop;
    _commands["display"] = &nts::Circuit::display;
    _commands["simulate"] = &nts::Circuit::simulate;
    _commands["exit"] = &nts::Circuit::exit;
}

const char *nts::Error::what() const noexcept
{
    return _error.c_str();
}

void nts::Circuit::sigHandler(int signum)
{
    if (signum == 2)
        Circuit::_loop = false;
}

void nts::Circuit::addComponent(std::string type, std::string name)
{
    std::string components[] = {"input", "output", "and", "nand",
                                "nor", "not", "or", "xor"};
    for (int i = 0; i != 8; ++i) {
        if (components[i] == type) {
            //TODO: Add factory
        }
    }
}

void nts::Circuit::setLoop()
{
    _loop = true;
}

void nts::Circuit::loop()
{
    while (_loop) {
        //simulate
        //display
    }
}

void nts::Circuit::display()
{
    std::cout << "display oui" << std::endl;
}

void nts::Circuit::simulate()
{
    std::cout << "simulate oui" << std::endl;
}

void nts::Circuit::exit()
{
    std::cout << "exit oui" << std::endl;
}

void nts::Circuit::setInputValue(std::string name, std::string state)
{
    if (stoi(state) > 2 || stoi(state) < 0)
        throw nts::Error("nts: Wrong input value");
    if (_components.find(name) == _components.end())
        throw nts::Error("nts: Input not found");
    _components[name]->setValue(static_cast<nts::Tristate>(stoi(state)));
}

void nts::Circuit::simulator()
{
    std::string input;
    std::vector<std::string> command;
    std::signal(SIGINT, Circuit::sigHandler);
    while (std::getline(std::cin, input)) {
        if (_loop)
            loop();
        if (!input.size())
            continue;
        command = ntsUtils::split(input, '=');
        if (command.size() == 2)
            setInputValue(command[0], command[1]);
        std::map<std::string, void (nts::Circuit::*)(void)>::const_iterator it;
        it = _commands.find(command[0]);
        if (it == _commands.end())
            throw nts::Error("nts: Command not found");
        ((*this).*(it->second))();
    }
}