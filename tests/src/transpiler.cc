//
// Created by mntcloud on 6/16/2023.
//

#include <doctest/doctest.h>
#include <lib182/transpiler.h>
#include <sstream>

TEST_CASE("must pass: replace single namespace statement's semicolon with curly-braces") {
    std::stringstream code(R"(
namespace Lovell;
struct Tokens {}
void lexer(char* code, std::vector<String> coll) {})");
    std::stringstream output;

    Transpiler tp;
    tp.through(code, output);

    CHECK(output.str() == "\nnamespace Lovell {\nstruct Tokens {}\nvoid lexer(char* code, std::vector<String> coll) {}\n}");
}