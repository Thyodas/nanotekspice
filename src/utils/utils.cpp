/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-guillaume.hein
** File description:
** utils.cpp
*/

#include "utils.hpp"

std::ifstream ntsUtils::openFile(std::string filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw nts::Error("ntsUtils: Failure to open file");
    return file;
}

std::vector<std::string> ntsUtils::split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void ntsUtils::parseChipsets(std::ifstream& file, nts::Circuit *circuit)
{
    std::string line;
    std::vector<std::string> results;
    while (!file.eof()) {
        std::getline(file, line);
        results = ntsUtils::split(line, ' ');
        if (results.empty() || results[0][0] == '\n' || results[0][0] == '#')
            continue;
        if (results[0] == ".links:")
            break;
        if (results.size() < 2 || results[0].find(":") != std::string::npos || results[1].find(":") != std::string::npos)
            throw nts::Error("nts: Wrong chipset formatting");
        std::string name = results[1];
        std::string type = results[0];
        //TODO: remove comment when adding the name
        std::cout << type << std::endl;
        std::cout << name << std::endl;
    }
}

void ntsUtils::parseLinks(std::ifstream& file, nts::Circuit *circuit)
{
    std::string line;
    std::vector<std::string> results;
    std::vector<std::string> tokens;
    while (!file.eof()) {
        std::getline(file, line);
        results = ntsUtils::split(line, ' ');
        if (results.empty())
            continue;
        if (results.size() < 2)
            throw nts::Error("nts: Wrong chipset formatting");
        tokens = ntsUtils::split(results[0], ':');
        std::string name1 = tokens[0];
        int link1 = std::stoi(tokens[1]);
        tokens = ntsUtils::split(results[1], ':');
        std::string name2 = tokens[0];
        int link2 = std::stoi(tokens[1]);
        //TODO: Remove comment when adding the name
        std::cout << name1 << std::endl;
        std::cout << link1 << std::endl;
        std::cout << name2 << std::endl;
        std::cout << link2 << std::endl;
    }
}

void ntsUtils::parseFile(std::ifstream& file, nts::Circuit *circuit)
{
    std::istringstream next;
    std::string line;
    while (!file.eof()) {
        std::getline(file, line);
        std::cout << line << std::endl;
        if (line == ".chipsets:") {
            parseChipsets(file, circuit);
            parseLinks(file, circuit);
            continue;
        }
        if (line[0] != '#' || line[0] != '\n')
            throw nts::Error("nts: Wrong file formatting");
    }
}
