#include <fstream>
#include <vector>
#include <tuple>
#include <string>
class Parser {
    std::vector<std::tuple<std::string, std::vector<int>,std::vector<std::string>>> DOM;
    void passHTML(std::ifstream HTMLFile);
};