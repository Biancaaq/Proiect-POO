#ifndef PALARIE_HPP
#define PALARIE_HPP

#include "Haina.hpp"


class Palarie : public Haina {
    public:
    Palarie();
    ~Palarie() override;

    bool upgrade(int& bani, Rucsac& rucsac) override;
    void setNivel2() override;
};


#endif