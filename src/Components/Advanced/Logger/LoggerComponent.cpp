/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** LoggerComponent.cpp
*/

#include "LoggerComponent.hpp"
#include "../../../Circuit.hpp"

void nts::LoggerComponent::simulate(std::size_t tick)
{
    if (_linkMap.find(InClock) == _linkMap.end()) {
        _file << "test1";
        return;
    }
    _linkMap.at(InClock).second->simulate(tick);
    if (getLink(InClock) != True || getLink(InInhibit) != False) {
        _file << "test2";
        return;
    }
    int res = 0;
    res |= getLink(In1);
    res |= getLink(In2) << 1;
    res |= getLink(In3) << 2;
    res |= getLink(In4) << 3;
    res |= getLink(In5) << 4;
    res |= getLink(In6) << 5;
    res |= getLink(In7) << 6;
    res |= getLink(In8) << 7;
    _file << ((char)res);
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
