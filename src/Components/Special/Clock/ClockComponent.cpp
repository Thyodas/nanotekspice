/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** ClockComponent.cpp
*/

#include "ClockComponent.hpp"

nts::Tristate nts::ClockComponent::compute(__attribute__((unused)) std::size_t pin)
{
    return _value;
}

nts::ClockComponent::ClockComponent()
: _value(Undefined)
{
    _validPins = {Output};
}

void nts::ClockComponent::simulate(std::size_t tick)
{
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
