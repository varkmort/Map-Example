#include "Init.hpp"

#include <fstream>
#include <sstream>

std::vector<NameRecord> GetNames() {
    std::vector<NameRecord> result;
    std::ifstream file("..\\namesDB\\russian_names.csv");
    if (!file.is_open()) {
        throw std::exception("file is't open");
    }
    std::string tmp;
    std::getline(file, tmp, '\n');
    while (!file.eof()) {
        std::getline(file, tmp, '\n');
        std::stringstream line;
        line << tmp;
        NameRecord dummy;
        line >> dummy;
        result.emplace_back(dummy.id, dummy.name, dummy.count, dummy.sex);
    }
    return result;
}
