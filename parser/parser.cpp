#include "parser.h"
#include <algorithm>
#include <iostream>
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
void Parser::passHTML(std::istream &HTMLFile) {
  std::string line;
  Node *current;
  while (std::getline(HTMLFile, line, '>')) {
    Node a;
    if (DOM.size() == 0) {
      a.name = line.substr(1);
      DOM.push_back(a);
      current = &DOM[0];
      continue;
    }
    if (line.find('/') == -1) {
      a.text = line.substr(0, line.find('<'));
      a.name = line.substr(line.find('<') + 1);
      current->children.push_back(a);
      std::stringstream attributes(line.substr(line.find('<') + 1));
      std::string attr;
      getline(attributes, attr, ' ');
      while (getline(attributes, attr, ' ')) {
        Param param;
        param.name = attr.substr(0, attr.find('='));
        param.value = attr.substr(attr.find('='));
        a.params.push_back(param);
      }
      auto ref = current;
      current = &current->children.back();
      current->parent = ref;
    } else {
      auto content = line.substr(0, line.find('<'));
      if (content.find_first_not_of(' ') != std::string::npos) {
        current->text = content;
      }
      current = current->parent;
    }
  }
  int spacer = 0;
  readChildren(DOM[0], spacer);
}