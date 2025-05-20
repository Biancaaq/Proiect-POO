#ifndef HAINA_HPP
#define HAINA_HPP

#include "Obiect.hpp"


class Haina : public Obiect {
protected:
    int nivel;
    int bonusStamina;
    int bonusViteza;
    int bonusScadereStamina;
    int bonusBuzunar;

public:
    Haina(const std::string& nume = "", float greutate = 0.0, int nivel = 1, int bonusStamina = 0, int bonusViteza = 0, int bonusScadereStamina = 0, int bonusBuzunar = 0);
    ~Haina() override;
};

#endif