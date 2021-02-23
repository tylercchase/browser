#include "parser.h"
#include <iostream>
void Parser::passHTML( std::ifstream &HTMLFile){
    DOM.push_back("Hi");
    std::cout << DOM[0] << std::endl;
    std::string line;
    while (std::getline(HTMLFile, line,'>')){
        std::cout << line << std::endl;
    }
}