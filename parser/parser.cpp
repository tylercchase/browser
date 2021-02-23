#include "parser.h"
#include <iostream>
void Parser::passHTML(const std::ifstream &HTMLFile){
    DOM.push_back("Hi");
    std::cout << DOM[0] << std::endl;
}