#ifndef LOOT_HPP
#define LOOT_HPP

#include "Obiect.hpp"


class Loot : public Obiect {
    protected:
    int raritate;

    public:
    Loot(const std::string& nume, float greutate, int raritate);
    ~Loot() override;

};

#endif