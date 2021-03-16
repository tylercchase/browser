#include "../parser/parser.h"
#include <catch2/catch.hpp>
#include <sstream>

TEST_CASE("1 is equal to 1") {
   REQUIRE(1 == 1);
   Parser parser;
   std::istringstream asdf("<html>\n<body>\n<a href=\"index.html\" target=\"_blank\">Link to something</a>\n<p>Hello World</p>\n<span>YOLO</span>\n\n</body>\n</html>");
   parser.passHTML(asdf);
}