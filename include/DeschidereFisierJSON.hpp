#ifndef UTILS_HPP
#define UTILS_HPP

#include <fstream>
#include <stdexcept>
#include <string>
#include <filesystem>
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
            std::cout << "[OK] Deschis fisier: " << cale << "\n";
            return f;
        }
    }

    std::cerr << "[Eroare] Nu s-a putut deschide fișierul " << nume << "\n";
    std::cerr << "[DEBUG] current_path(): " << std::filesystem::current_path() << "\n";
    throw std::runtime_error("Nu s-a putut deschide fișierul " + nume);
}

#endif
