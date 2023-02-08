#ifndef TOOLFUNCTIONS
#define TOOLFUNCTIONS

#include <iostream>
#include <fstream>
#include <sstream>

#include "StringHepler.h"

inline std::string readFile(const char *file_path) {
    std::ifstream file;
    file.open(file_path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    return buffer.str();;
}

#endif // !TOOLFUNCTIONS
