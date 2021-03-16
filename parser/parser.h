#include <fstream>
#include <string>
#include <tuple>
#include <vector>
struct Param {
  std::string name;
  std::string value;
};
class Node {
public:
  std::string text;
  std::string name;
  Node *parent;
  std::vector<Param> params;
  std::vector<Node> children;
};
class Parser {
public:
  void passHTML(std::istream &HTMLFile);
  std::vector<Node> DOM = {};
};
