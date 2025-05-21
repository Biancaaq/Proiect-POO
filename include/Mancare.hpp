#ifndef MANCARE_HPP
#define MANCARE_HPP

#include "Loot.hpp"


class Mancare : public Loot {
    int energieRecuperata;
    bool procesata;

    public:
    Mancare(const std::string& nume, double greutate, int raritate, const std::string& tip, int energie, bool procesata = false);
    ~Mancare() override;

    std::string getTip() const override;
};

#endif