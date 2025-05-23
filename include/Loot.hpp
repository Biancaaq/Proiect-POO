#ifndef LOOT_HPP
#define LOOT_HPP

#include "Obiect.hpp"


class Loot : public Obiect {
    protected:
    int raritate;
    int pret;

    public:
    Loot(const std::string& nume, double greutate, int raritate, int pret);
    ~Loot() override;

    int getRaritate() const;
    int getPret() const;

};

#endif