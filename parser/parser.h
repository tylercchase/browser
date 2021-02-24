#include <fstream>
#include <vector>
#include <tuple>
#include <string>
struct Param{
    std::string name;
    std::string value;
};
class Node{
    public:
        std::string      text;
        std::string      name;
        Node* parent;
        std::vector<Param> params;
        std::vector<Node> children;
};
class Parser
{
    // std::vector<std::tuple<std::string, std::vector<int>,std::vector<std::string>>> DOM;
private:
    std::vector<Node> DOM = {};

public:
    void passHTML(std::ifstream &HTMLFile);
};
