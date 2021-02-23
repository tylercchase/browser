#include <sstream>
using std::ostringstream;
#include "../parser/parser.h"
#include <istream>
#include "../catch.hpp"

TEST_CASE("1 is equal to 1") {
   REQUIRE(1 == 1);
   Parser parser;
   std::ifstream testFile("test.html");
   parser.passHTML(testFile);
}