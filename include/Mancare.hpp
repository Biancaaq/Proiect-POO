#ifndef MANCARE_HPP
#define MANCARE_HPP

#include "Loot.hpp"


class Mancare : public Loot {
    int energieRecuperata;

    public:
    Mancare(const std::string& nume, float greutate, int raritate, int energie);
    ~Mancare() override;
};

#endif