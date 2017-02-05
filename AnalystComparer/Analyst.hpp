//
// Created by manab on 2/1/2017.
//

#ifndef ASSIGN2_ANALYST_HPP
#define ASSIGN2_ANALYST_HPP


#include <string>
#include "History.hpp"

class Analyst {
public:
    Analyst(std::string fileName);
    void createHistory();
    History getHistory() const;
    std::string getName() const;
private:
    History* history;
    std::string name;
    std::string initials;
};


#endif //ASSIGN2_ANALYST_HPP
