#include "../parser/parser.h"
#include "../catch.hpp"
#include <istream>

TEST_CASE("1 is equal to 1") {
   REQUIRE(1 == 1);
   Parser parser;
   std::ifstream testFile("test.html");
   parser.passHTML(testFile);
}