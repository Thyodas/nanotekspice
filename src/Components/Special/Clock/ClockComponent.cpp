/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** ClockComponent.cpp
*/

#include "ClockComponent.hpp"

nts::Tristate nts::ClockComponent::recompute(__attribute__((unused)) std::size_t pin)
{
    return _value;
}

nts::ClockComponent::ClockComponent()
: _value(Undefined), _newValue(Undefined), _toSet(false)
{
    _validPins = {Output};
    _outputPins = {Output};
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    if (_toSet) {
        _value = _newValue;
        _toSet = false;
        _tick = tick;
        return;
    }
    if (tick % 2 == _tick % 2)
        return;
    switch (_value) {
        case True:
            _value = False;
            break;
        case False:
            _value = True;
            break;
        case Undefined:
            break;
    }
    _tick = tick;
}

void nts::ClockComponent::setValue(nts::Tristate value)
{
    _newValue = value;
    _toSet = true;
}
