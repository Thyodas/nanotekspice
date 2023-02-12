/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-guillaume.hein
** File description:
** main.cpp
*/

#include "utils/utils.hpp"
#include <vector>

int main(int argc, char **argv)
{
    try {
        if (argc != 2)
            throw nts::Error("nts: Invalid number of arguments");
        nts::Circuit *circuit = new nts::Circuit;
        std::ifstream file = ntsUtils::openFile(argv[1]);
        ntsUtils::parseFile(file, circuit);
        circuit->simulator();
        delete circuit;
        return 0;
    } catch (const nts::Error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
