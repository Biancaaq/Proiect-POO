#ifndef BLUZA_H
#define BLUZA_H

#include "Haina.hpp"

class Bluza : public Haina {
public:
    Bluza();
    ~Bluza() override;

    void upgrade() override;
};

#endif