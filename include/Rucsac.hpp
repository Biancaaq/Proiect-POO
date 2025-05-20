#ifndef RUCSAC_HPP
#define RUCSAC_HPP

#include "Obiect.hpp"


class Rucsac : public Obiect {
    protected:
    int nivel;
    float capacitate;

    public:
    Rucsac(const std::string& nume = "Rucsac simplu", float greutate = 1.5, int nivel = 1, float capacitate = 10.0);
    ~Rucsac() override;
};

#endif