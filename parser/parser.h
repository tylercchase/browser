#include <fstream>
#include <vector>
#include <tuple>
#include <string>
class Parser
{
    // std::vector<std::tuple<std::string, std::vector<int>,std::vector<std::string>>> DOM;
private:
    std::vector<std::string> DOM = {};

public:
    void passHTML(std::ifstream &HTMLFile);
};