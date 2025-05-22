#ifndef MANCARE_HPP
#define MANCARE_HPP

#include "Loot.hpp"


class Mancare : public Loot {
    int energieRecuperata;

    public:
    Mancare(const std::string& nume, double greutate, int raritate, int pret, int energie);
    ~Mancare() override;

    int getEnergieRecuperata() const;
};

#endif