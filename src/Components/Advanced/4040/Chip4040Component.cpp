/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Chip4040Component.cpp
*/

#include "Chip4040Component.hpp"

void nts::Chip4040Component::simulate(__attribute__((unused)) std::size_t tick)
{
    _prevClock = _clock;
}


nts::Tristate nts::Chip4040Component::recompute(std::size_t pin)
{
    if (!_outputPins.contains(pin))
        return getLink(pin);
    _clock = getLink(C);
    Tristate reset = getLink(R);
    if (_clock == Undefined || reset == Undefined)
        return Undefined;
    if (getLink(R) == True) {
        _count = 0;
        return False;
    }
    if (_prevClock == Undefined)
        return Undefined;
    if (_clock == True) {
        return _prevComputeCacheMap.contains(pin) ?
               _prevComputeCacheMap.at(pin) : Undefined;
    }
    if (_clock == False)
        _count = (_count + (uint16_t)(1)) % 4096;
    _computeCacheMap[Q1] = (Tristate)!!(_count & (1 << 0));
    _computeCacheMap[Q2] = (Tristate)!!(_count & (1 << 1));
    _computeCacheMap[Q3] = (Tristate)!!(_count & (1 << 2));
    _computeCacheMap[Q4] = (Tristate)!!(_count & (1 << 3));
    _computeCacheMap[Q5] = (Tristate)!!(_count & (1 << 4));
    _computeCacheMap[Q6] = (Tristate)!!(_count & (1 << 5));
    _computeCacheMap[Q7] = (Tristate)!!(_count & (1 << 6));
    _computeCacheMap[Q8] = (Tristate)!!(_count & (1 << 7));
    _computeCacheMap[Q9] = (Tristate)!!(_count & (1 << 8));
    _computeCacheMap[Q10] = (Tristate)!!(_count & (1 << 9));
    _computeCacheMap[Q11] = (Tristate)!!(_count & (1 << 10));
    _computeCacheMap[Q12] = (Tristate)!!(_count & (1 << 11));
    return _computeCacheMap.at(pin);
}

nts::Chip4040Component::Chip4040Component()
: _clock(Undefined), _prevClock(Undefined), _count(0)
{
    _validPins = {Q12, Q6, Q5, Q7, Q4, Q3, Q2, Q11, Q10, Q8, Q9, R, C, Q1};
    _outputPins = {Q12, Q6, Q5, Q7, Q4, Q3, Q2, Q11, Q10, Q8, Q9, Q1};
}
