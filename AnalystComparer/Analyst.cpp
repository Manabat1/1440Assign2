//
// Created by manab on 2/1/2017.
//
#include <fstream>
#include "Analyst.hpp"
#include "Utils.h"

Analyst::Analyst(std::string fileName){
    std::ifstream fin;
    fin.open(fileName);
    std::string line;
    name = getTrimmedLine(fin);
    initials = getTrimmedLine(fin);
    History* history = new History(fin);
}

std::string Analyst::getName() const {
    return name;
}

History Analyst::getHistory() const {
    return *history;
}
