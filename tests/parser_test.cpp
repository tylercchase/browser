#include "../parser/parser.h"
#include <catch2/catch.hpp>
#include <istream>

TEST_CASE("1 is equal to 1") {
   REQUIRE(1 == 1);
   Parser parser;
   std::ifstream testFile("/home/tcchase/projects/browser/test.html"); // aboslute path for testing
   parser.passHTML(testFile);
}