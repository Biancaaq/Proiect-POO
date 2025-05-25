#ifndef DESCHIDERE_FISIER_JSON_HPP
#define DESCHIDERE_FISIER_JSON_HPP

#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>

inline std::ifstream deschideFisierJson(const std::string& nume) {
    std::ifstream f;

    std::string variante[] = {
        nume,
        "resurse/" + nume,
        "../resurse/" + nume
    };

    for (const auto& cale : variante) {
        f.open(cale);
        if (f.is_open()) {
            return f;
        }
    }

  throw std::runtime_error("Nu s-a putut deschide fisierul " + nume);
}

#endif
