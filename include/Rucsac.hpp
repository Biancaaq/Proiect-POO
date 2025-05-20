#ifndef RUCSAC_HPP
#define RUCSAC_HPP

#include "Obiect.hpp"


class Rucsac : public Obiect {
    protected:
    int nivel;
    double capacitate;

    public:
    explicit Rucsac(const std::string& nume = "Rucsac simplu", double greutate = 1.5, int nivel = 1, double capacitate = 10.0);
    ~Rucsac() override;
};

#endif