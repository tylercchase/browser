#include "../parser/parser.h"
#include <catch2/catch.hpp>
#include <iostream>
#include <sstream>

TEST_CASE("1 is equal to 1") {
  REQUIRE(1 == 1);
  Parser parser;
  std::istringstream asdf("<html>\n<body>\n<a href=\"index.html\" "
                          "target=\"_blank\">Link to something</a>\n<p>Hello "
                          "World</p>\n<span>YOLO</span>\n\n</body>\n</html>");
  parser.passHTML(asdf);
  SECTION("Name parsing for basic html elements") {
    REQUIRE(parser.DOM[0].name == "html");
    REQUIRE(parser.DOM[0].children[0].name == "body");
    REQUIRE(parser.DOM[0].children[0].children[0].name == "a");
    REQUIRE(parser.DOM[0].children[0].children[1].name == "p");
    REQUIRE(parser.DOM[0].children[0].children[2].name == "span");
  }
  SECTION("Attribute parsing") {
    REQUIRE(parser.DOM[0].children[0].children[0].params[0].name == "href");
    REQUIRE(parser.DOM[0].children[0].children[0].params[0].value == "index.html");
    REQUIRE(parser.DOM[0].children[0].children[0].params[1].name == "target");
    REQUIRE(parser.DOM[0].children[0].children[0].params[1].value == "_blank");
  }
}