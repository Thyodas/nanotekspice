/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-guillaume.hein
** File description:
** utils.cpp
*/

#include "utils.hpp"

std::string ntsUtils::rtrim(const std::string &s)
{
    const std::string WHITESPACE = " \t\f\v";
    std::size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

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
        token = rtrim(token);
        if (token == "")
            continue;
        tokens.push_back(token);
    }
    return tokens;
}

void ntsUtils::parseChipsets(std::ifstream& file, nts::Circuit *circuit)
{
    std::string line;
    std::vector<std::string> results;
    nts::ComponentFactory factory;
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
        circuit->addComponent(type, name, &factory);
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
        if (results.empty() || results[0][0] == '#' || results[0][0] == '\n')
            continue;
        if (results.size() < 2)
            throw nts::Error("nts: Wrong chipset formatting");
        tokens = ntsUtils::split(results[0], ':');
        if (tokens.size() != 2)
            throw nts::Error("nts: Missing links");
        std::string name1 = tokens[0];
        std::size_t link1 = std::stoi(tokens[1]);
        tokens = ntsUtils::split(results[1], ':');
        if (tokens.size() != 2)
            throw nts::Error("nts: Missing links");
        std::string name2 = tokens[0];
        //Remove comment
        std::istringstream iss(tokens[1]);
        std::string token2Cleared;
        std::getline(iss, token2Cleared, '#');
        token2Cleared = rtrim(token2Cleared);
        if (token2Cleared.empty())
            throw nts::Error("nts: Missing links");
        std::size_t link2 = std::stoi(token2Cleared);
        circuit->setLinks(name1, link1, name2, link2);
    }
}

void ntsUtils::parseFile(std::ifstream& file, nts::Circuit *circuit)
{
    std::istringstream next;
    std::string line;
    while (!file.eof()) {
        std::getline(file, line);
        std::istringstream iss(line);
        std::string lineCleared;
        std::getline(iss, lineCleared, '#');
        if (lineCleared == ".chipsets:") {
            parseChipsets(file, circuit);
            parseLinks(file, circuit);
            continue;
        }
        if (line.size() != 0 && line[0] != '#' && line[0] != '\n')
            throw nts::Error("nts: Wrong file formatting");
    }
}
