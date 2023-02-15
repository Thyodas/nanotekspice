/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** LoggerComponent.cpp
*/

#include "LoggerComponent.hpp"
#include "../../../Circuit.hpp"

bool nts::LoggerComponent::simulateAllInputs(std::size_t tick)
{
    for (const auto &pin: _validPins) {
        if (_linkMap.find(pin) == _linkMap.end())
            return true;
        auto pair = _linkMap.at(pin);
        pair.second->simulate(tick);
        if (getLink(pin) == Undefined)
            return true;
    }
    return false;
}

void nts::LoggerComponent::simulate(std::size_t tick)
{
    if (simulateAllInputs(tick))
        return;
    if (getLink(InClock) != True || getLink(InInhibit) != False)
        return;
    int res = 0;
    res |= getLink(In1);
    res |= getLink(In2) << 1;
    res |= getLink(In3) << 2;
    res |= getLink(In4) << 3;
    res |= getLink(In5) << 4;
    res |= getLink(In6) << 5;
    res |= getLink(In7) << 6;
    res |= getLink(In8) << 7;
    _file << ((char)res) << std::flush;
}

nts::Tristate nts::LoggerComponent::compute(std::size_t pin)
{
    return getLink(pin);
}

nts::LoggerComponent::LoggerComponent()
{
    _validPins = {In1, In2, In3, In4, In5, In6, In7, In8, InClock, InInhibit};
    _file.open("./log.bin", std::ios::app);
    if (_file.bad())
        throw nts::Error("Couldn't open file './log.bin'.");
}

nts::LoggerComponent::~LoggerComponent()
{
    _file.close();
}
