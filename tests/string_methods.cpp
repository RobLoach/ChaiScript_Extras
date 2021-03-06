#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <string>
#include "catch.hpp"

#include <chaiscript/chaiscript.hpp>
#include <chaiscript/chaiscript_stdlib.hpp>
#include "../include/chaiscript/extras/string_methods.hpp"

TEST_CASE( "string_methods functions work", "[string_methods]" ) {
  auto stdlib = chaiscript::Std_Lib::library();
  chaiscript::ChaiScript chai(stdlib);

  // Add the string_methods module.
  auto stringmethods = chaiscript::extras::string_methods::bootstrap();
  chai.add(chaiscript::bootstrap::standard_library::vector_type<std::vector<std::string>>("StringVector"));
  chai.add(stringmethods);

  // replace(string, string)
  CHECK(chai.eval<std::string>("\"Hello World!\".replace(\"Hello\", \"Goodbye\")") == "Goodbye World!");

  // replace(char, char)
  CHECK(chai.eval<std::string>("\"Hello World!\".replace('e', 'i')") == "Hillo World!");

  // trim()
  CHECK(chai.eval<std::string>("\"   Hello World!    \".trim()") == "Hello World!");

  // split()
  CHECK(chai.eval<std::string>("\"Hello,World,How,Are,You\".split(\",\")[1]") == "World");

  // toLowerCase()
  CHECK(chai.eval<std::string>("\"HeLLO WoRLD!\".toLowerCase()") == "hello world!");

  // toUpperCase()
  CHECK(chai.eval<std::string>("\"Hello World!\".toUpperCase()") == "HELLO WORLD!");
}
