/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-guillaume.hein
** File description:
** Circuit.cpp
*/

#include "Circuit.hpp"

nts::Error::Error(std::string error)
{
    _error = error;
}

const char *nts::Error::what() const noexcept
{
    return _error.c_str();
}