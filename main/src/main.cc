#include <iostream>
#include <fstream>
#include <cxxopts.hpp>

#include <lib182/transpiler.h>

int main(int argc, char *argv[]) {
    cxxopts::Options options("182", "kinda transpiler for C++");
    options.add_options()
            ("infile", "The filename to transpile", cxxopts::value<std::string>())
            ("outfile", "The filename for output", cxxopts::value<std::string>())
            ("help", "Print usage");

    options.parse_positional({"infile", "outfile"});

    options.positional_help("infile outfile");

    auto result = options.parse(argc, argv);

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        exit(0);
    }

    auto infile_path = result["infile"].as<std::string>();
    auto outfile_path = result["outfile"].as<std::string>();

    std::fstream fin(infile_path, std::ios::in);
    std::fstream fout(outfile_path, std::ios::out);

    Transpiler tp;

    tp.through(fin, fout);

    return 0;
}
