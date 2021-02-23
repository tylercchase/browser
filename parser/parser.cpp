#include "parser.h"
#include <iostream>

void Parser::passHTML(std::ifstream &HTMLFile)
{
    std::string line;
    Node * current;
    while (std::getline(HTMLFile, line, '>'))
    {
        Node a;
        if(DOM.size() == 0){
            a.name = line.substr(1);
            DOM.push_back(a);
            current = &DOM[0];
            continue;
        }
        if (line.find('/') == -1)
        {
            line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
            line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

            a.name = line;
            current->children.push_back(a);
            auto ref = current;
            current = &current->children[0];
            current->parent = ref;
        }
        else
        {
            current = current->parent;
        }
    }
    for (auto &node : DOM)
    {
        std::cout << node.name << std::endl;
        std::cout << node.children[0].children[0].name << std::endl;
    }
}