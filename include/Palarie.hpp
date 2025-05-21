#ifndef PALARIE_HPP
#define PALARIE_HPP

#include "Haina.hpp"


class Palarie : public Haina {
    public:
    Palarie();
    ~Palarie() override;

    void upgrade() override;
};

#endif