/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** ComponentFactory.cpp
*/

#include "ComponentFactory.hpp"
#include "../Circuit.hpp"

// All Special
#include "Special/Input/InputComponent.hpp"
#include "Special/Clock/ClockComponent.hpp"
#include "Special/Output/OutputComponent.hpp"
#include "Special/False/FalseComponent.hpp"
#include "Special/True/TrueComponent.hpp"

// All Elementary
#include "Elementary/Or/OrComponent.hpp"
#include "Elementary/And/AndComponent.hpp"
#include "Elementary/Xor/XorComponent.hpp"
#include "Elementary/Nand/NandComponent.hpp"
#include "Elementary/Nor/NorComponent.hpp"

// All Gate
#include "Gate/4001/Chip4001Component.hpp"
#include "Gate/4011/Chip4011Component.hpp"
#include "Gate/4030/Chip4030Component.hpp"
#include "Gate/4069/Chip4069Component.hpp"
#include "Gate/4071/Chip4071Component.hpp"
#include "Gate/4081/Chip4081Component.hpp"

nts::ComponentFactory::~ComponentFactory() = default;

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(
    const std::string &name)
{
    if (_constructorMap.find(name) == _constructorMap.end())
        throw nts::Error("Unknown component '" + name + "'.");
    return _constructorMap.at(name)();
}

void nts::ComponentFactory::registerComponent(const std::string &name,
             const std::function<std::unique_ptr<IComponent>()> &constructor)
{
    _constructorMap[name] = constructor;
}

nts::ComponentFactory::ComponentFactory()
{
    // Special
    registerComponent("clock", []() {
        return std::make_unique<ClockComponent>();
    });
    registerComponent("false", []() {
        return std::make_unique<FalseComponent>();
    });
    registerComponent("input", []() {
        return std::make_unique<InputComponent>();
    });
    registerComponent("output", []() {
        return std::make_unique<OutputComponent>();
    });
    registerComponent("true", []() {
        return std::make_unique<TrueComponent>();
    });

    // Elementary
    registerComponent("and", []() {
        return std::make_unique<AndComponent>();
    });
    registerComponent("or", []() {
        return std::make_unique<OrComponent>();
    });
    registerComponent("xor", []() {
        return std::make_unique<XorComponent>();
    });
    registerComponent("not", []() {
        return std::make_unique<NotComponent>();
    });
    registerComponent("nand", []() {
        return std::make_unique<NandComponent>();
    });
    registerComponent("nor", []() {
        return std::make_unique<NorComponent>();
    });

    // Gate
    registerComponent("4001", []() {
        return std::make_unique<Chip4001Component>();
    });
    registerComponent("4011", []() {
        return std::make_unique<Chip4011Component>();
    });
    registerComponent("4030", []() {
        return std::make_unique<Chip4030Component>();
    });
    registerComponent("4069", []() {
        return std::make_unique<Chip4069Component>();
    });
    registerComponent("4071", []() {
        return std::make_unique<Chip4071Component>();
    });
    registerComponent("4081", []() {
        return std::make_unique<Chip4081Component>();
    });
}
