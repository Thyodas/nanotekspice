/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-guillaume.hein
** File description:
** Circuit.cpp
*/

#include "Circuit.hpp"
#include "utils/utils.hpp"
#include "Components/Special/Input/InputComponent.hpp"
#include "Components/Special/Output/OutputComponent.hpp"
#include <utility>
#include <csignal>
#include <vector>
#include <map>
#include <sstream>
#include <bits/stdc++.h>

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
    _ticks = 0;
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

void nts::Circuit::addComponent(std::string type, std::string name, nts::ComponentFactory *factory)
{
    std::istringstream iss(name);
    std::string nameCleared;
    std::getline(iss, nameCleared, '#');
    nameCleared = ntsUtils::rtrim(nameCleared);
    if (_components.find(nameCleared) != _components.end())
        throw nts::Error("nts: Two components have the same name");
    std::unique_ptr<nts::IComponent> newComponent = factory->createComponent(type);
    _components[nameCleared] = std::move(newComponent);
}

void nts::Circuit::setLinks(std::string name1, std::size_t pin1, std::string name2, std::size_t pin2)
{
    if (_components.find(name1) == _components.end() || _components.find(name2) == _components.end())
        throw nts::Error("nts: Components not found");
    nts::IComponent *component1 = _components[name1].get();
    nts::IComponent *component2 = _components[name2].get();
    component1->setLink(pin1, *component2, pin2);
    component2->setLink(pin2, *component1, pin1);
}

void nts::Circuit::setLoop()
{
    _loop = true;
}

void nts::Circuit::loop()
{
    while (_loop) {
        simulate();
        display();
    }
}

void nts::Circuit::display()
{
    std::vector<std::string> inputs;
    std::vector<std::string> outputs;
    std::cout << "tick: " << _ticks << std::endl;
    for (const auto &it : _components) {
        if (dynamic_cast<nts::InputComponent *>(it.second.get()))
            inputs.push_back(it.first);
        if (dynamic_cast<nts::OutputComponent *>(it.second.get()))
            outputs.push_back(it.first);
    }
    std::sort(inputs.begin(), inputs.end());
    std::sort(outputs.begin(), outputs.end());
    std::cout << "input(s):" << std::endl;
    for (std::size_t i = 0; i < inputs.size(); ++i) {
        std::cout << "   " << inputs[i] << ": ";
        std::cout << _components[inputs[i]]->compute(1) << std::endl;
    }
    std::cout << "output(s)" << std::endl;
    for (std::size_t i = 0; i < outputs.size(); ++i) {
        std::cout << "   " << outputs[i] << ": ";
        std::cout << _components[outputs[i]]->compute(1) << std::endl;
    }
    std::cout << "> ";
}

void nts::Circuit::simulate()
{
    _ticks++;
    for (const auto &it : _components)
        it.second->simulate(_ticks);
}

void nts::Circuit::exit()
{
    _exit = true;
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
    std::cout << "> ";
    while (!_exit && std::getline(std::cin, input)) {
        if (_loop)
            loop();
        std::cout << "> ";
        if (!input.size())
            continue;
        command = ntsUtils::split(input, '=');
        if (command.size() == 2) {
            setInputValue(command[0], command[1]);
            continue;
        }
        std::map<std::string, void (nts::Circuit::*)(void)>::const_iterator it;
        it = _commands.find(command[0]);
        if (it == _commands.end())
            throw nts::Error("nts: Command not found");
        ((*this).*(it->second))();
    }
}