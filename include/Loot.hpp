#ifndef LOOT_HPP
#define LOOT_HPP

#include "Obiect.hpp"


class Loot : public Obiect {
    protected:
    int raritate;
    std::string tip;

    public:
    Loot(const std::string& nume, double greutate, int raritate, const std::string& tip);
    ~Loot() override;

    virtual std::string getTip() const = 0;

};

#endif