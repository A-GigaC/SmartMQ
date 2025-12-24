#include <yaml-cpp/yaml.h>
#include <stdio.h>
#include <iostream>
#include "config.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage:\n\t > SmartMQ.broker {CONFIG-FILE-PATH}" << std::endl;
    }
    auto config = Config::fromFile(argv[1]);
    return 0;
}