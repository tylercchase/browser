#include <fstream>
#include <vector>
#include <tuple>
#include <string>
class Node{
    struct Param{
    std::string name;
    std::string value;
    };
    public:
    std::string      text;
    std::string      name;
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
