//
// Created by mntcloud on 6/13/2023.
//

#include <lib182/transpiler.h>
#include <iostream>

void Transpiler::through(io_stream& code, io_stream& output) {
    char symbol;

    while (!code.eof()) {
        code.get(symbol);

        // just in case check for eofbit
        if (code.eof()) {
            break;
        }

        if (!this->to_break(symbol)) {
            this->token.push_back(symbol);
            continue;
        }

        std::string joined(this->token.begin(), this->token.end());

        if (this->current_keyword == token_type::NAMESPACE) {
            char end_symbol = this->token[this->token.size() - 1];

            if (end_symbol == ';') {
                joined.pop_back();
                output << joined << " {\n";
            }

            this->current_keyword = token_type::SOMETHING_ELSE;
            this->clear_token();
            continue;
        }

        if (joined == "namespace") {
            this->current_keyword = token_type::NAMESPACE;
        }

        output << joined << symbol;
        this->clear_token();
    }

    // TODO: need to rewrite the cycle to make cycle's condition check after completing body
    std::string bits(token.begin(), token.end());

    if (this->current_keyword == token_type::SOMETHING_ELSE)
        output << bits << "\n}";
}

// Just a function-wrapper with an intuitive name
// @param sym
//            A character, that will be checked
bool Transpiler::to_break(char sym) {
    return isspace(sym);
}

void Transpiler::clear_token() {
    this->token.clear();
    this->token.shrink_to_fit();
}