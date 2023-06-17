//
// Created by mntcloud on 6/13/2023.
//

#include <vector>
#include <tuple>
#include <istream>

typedef std::basic_iostream<char, std::char_traits<char>> io_stream;

enum token_type {
    NAMESPACE,
    SOMETHING_ELSE
};

class Transpiler {
private:
    std::vector<char> token;
    token_type current_keyword;

    void clear_token();
    static bool to_break(char sym);
public:
    void through(io_stream& code, io_stream& output);
};
