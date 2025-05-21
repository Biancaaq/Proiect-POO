#ifndef PANTALONI_HPP
#define PANTALONI_HPP

#include "Haina.hpp"

class Pantaloni : public Haina {
public:
    Pantaloni();
    ~Pantaloni() override;

    bool upgrade(int& bani, Rucsac& rucsac) override;
};

#endif