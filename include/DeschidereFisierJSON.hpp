#ifndef UTILS_HPP
#define UTILS_HPP

#include <fstream>
#include <stdexcept>
#include <string>

inline std::ifstream deschideFisierJson(const std::string& nume) {
    std::ifstream f(nume);
    if (!f.is_open())
        f.open("../" + nume);
    if (!f.is_open())
        throw std::runtime_error("Nu s-a putut deschide fișierul " + nume);
    return f;
}

#endif
