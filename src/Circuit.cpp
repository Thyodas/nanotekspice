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
#include <sstream>
#include <algorithm>

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
        throw nts::Error("nts: Two components have the same name " + nameCleared);
    std::unique_ptr<nts::IComponent> newComponent = factory->createComponent(type);
    _components[nameCleared] = std::move(newComponent);
    if (type == "input" || type == "clock")
        _inputs.push_back(nameCleared);
    if (type == "output")
        _outputs.push_back(nameCleared);
    std::sort(_inputs.begin(), _inputs.end());
    std::sort(_outputs.begin(), _outputs.end());
}

void nts::Circuit::setLinks(std::string name1, std::size_t pin1, std::string name2, std::size_t pin2)
{
    if (_components.find(name1) == _components.end() || _components.find(name2) == _components.end())
        throw nts::Error("nts: Component not found");
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
    for (auto &item: _components)
        item.second->findRing(&(*item.second), {});
    std::cout << "tick: " << _ticks << std::endl;
    std::cout << "input(s):" << std::endl;
    for (std::size_t i = 0; i < _inputs.size(); ++i) {
        std::cout << "  " << _inputs[i] << ": ";
        std::cout << _components[_inputs[i]]->compute(1) << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (std::size_t i = 0; i < _outputs.size(); ++i) {
        std::cout << "  " << _outputs[i] << ": ";
        std::cout << _components[_outputs[i]]->compute(1) << std::endl;
    }
}

void nts::Circuit::simulate()
{
    _ticks++;
    for (const auto &it : _components) {
        it.second->resetCache();
        it.second->simulate(_ticks);
    }
}

void nts::Circuit::exit()
{
    _exit = true;
}

void nts::Circuit::setInputValue(std::string name, std::string state)
{
    if (state.find_first_not_of("01U") != std::string::npos)
        throw nts::Error("nts: Wrong input value");
    if (_components.find(name) == _components.end())
        throw nts::Error("nts: Input not found");
    if (state == "U")
        _components[name]->setValue(nts::Tristate::Undefined);
    else
        _components[name]->setValue(static_cast<nts::Tristate>(stoi(state)));
}

void nts::Circuit::simulator()
{
    if (!_components.size())
        throw nts::Error("nts: No chipsets provided");
    std::string input;
    std::vector<std::string> command;
    std::signal(SIGINT, Circuit::sigHandler);
    std::cout << "> ";
    while (!_exit && std::getline(std::cin, input)) {
        if (!input.size())
            continue;
        command = ntsUtils::split(input, '=');
        if (command.size() == 2) {
            setInputValue(command[0], command[1]);
            std::cout << "> ";
            continue;
        }
        std::map<std::string, void (nts::Circuit::*)(void)>::const_iterator it;
        it = _commands.find(command[0]);
        if (it == _commands.end())
            throw nts::Error("nts: Command not found");
        ((*this).*(it->second))();
        if (_loop)
            loop();
        if (!_exit)
            std::cout << "> ";
    }
}