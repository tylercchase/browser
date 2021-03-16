cmake_minimum_required(VERSION 3.0.0)
project(browser VERSION 0.1.0)

include(CTest)
enable_testing()
set (CMAKE_CXX_STANDARD 20)
find_package(SFML
  COMPONENTS 
    system window graphics network audio REQUIRED)

add_executable(gui graphics_main.cpp)
target_link_libraries(gui sfml-graphics)

add_executable(tests main.cpp tests/parser_test.cpp parser/parser.h parser/parser.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
