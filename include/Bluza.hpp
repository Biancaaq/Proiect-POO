#ifndef BLUZA_H
#define BLUZA_H

#include "Haina.hpp"

class Bluza : public Haina {
public:
    Bluza();
    ~Bluza() override;

    bool upgrade(int& bani, Rucsac& rucsac) override;
    void setNivel2() override;
};

#endif