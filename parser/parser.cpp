#include "parser.h"
#include <iostream>
#include <algorithm>
void readChildren(Node &x, int spacer){
    for(int i=0; i < spacer; ++i){
        std::cout << " ";
    }
    std::cout << x.name << std::endl;
    std::for_each(x.children.begin(),x.children.end(), [spacer](Node &n){ readChildren(n,spacer+1); });
};
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
            a.text = line.substr(0,line.find('<'));
            a.name = line.substr(line.find('<')+1);
            current->children.push_back(a);
            auto ref = current;
            current = &current->children.back();
            current->parent = ref;
        }
        else
        {
            auto content = line.substr(0,line.find('<'));
            if(content.find_first_not_of(' ') != std::string::npos)
            {
                current->text = content;
            }
            current = current->parent;
        }
    }
    int spacer = 0;
    readChildren(DOM[0],spacer);
}