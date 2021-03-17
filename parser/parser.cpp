#include "parser.h"
#include <algorithm>
<<<<<<< Updated upstream
#include <iostream>
=======
#include <string>
>>>>>>> Stashed changes
#include <sstream>
void readChildren(Node &x, int spacer) {
  for (int i = 0; i < spacer; ++i) {
    std::cout << " ";
  }
  std::cout << x.name;
  for (auto attr : x.params) {
    std::cout << " " << attr.name << "=" << attr.value;
  }
  std::cout << std::endl;
  std::for_each(x.children.begin(), x.children.end(),
                [spacer](Node &n) { readChildren(n, spacer + 1); });
};
void Parser::passHTML( std::istream &HTMLFile)
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
            bool spaceFlag = false;
            bool attrFlag = false;
            bool quoteFlag = false;
            Param param;
            for(auto &character: line) {
                if(!spaceFlag && std::isspace(character)) {
                    spaceFlag = true;
                }
                if(spaceFlag) {
                    if(!attrFlag && !std::isspace(character)) {
                        if(character == '=') {
                            attrFlag = true;
                        }
                        else {
                            param.name += character;
                        }
                    } else if(attrFlag) {
                        if(!quoteFlag && character == '"')
                         {

                        }
                    }
                    else {
                        
                    }
                } else {
                    a.name += character;
                }
            }
            a.text = line.substr(0,line.find('<'));
            a.name = line.substr(line.find('<')+1);
            if(line.find(' ') != std::string::npos) {
                a.name = line.substr(line.find('<')+1,line.find(' ')-2);
            }
            current->children.push_back(a);
            std::stringstream attributes(line.substr(line.find('<')+1));
            std::string attr;
            getline(attributes,attr, ' ');
            while(getline(attributes, attr, ' ')){
                Param param;
                param.name = attr.substr(0,attr.find('='));
                param.value = attr.substr(attr.find('='));
                a.params.push_back(param);
            }
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
  }
  int spacer = 0;
  readChildren(DOM[0], spacer);
}