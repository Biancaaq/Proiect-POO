#ifndef HAINA_HPP
#define HAINA_HPP

#include "Obiect.hpp"
#include "Rucsac.hpp"


class Haina : public Obiect {
protected:
    int nivel;
    int bonusStamina;
    int bonusReducereScadereStamina;
    double bonusBuzunar;

public:
    explicit Haina(const std::string& nume = "", double greutate = 0.0, int nivel = 1, int bonusStamina = 0, int bonusReducereScadereStamina = 0, double bonusBuzunar = 0.0);
    ~Haina() override;

    virtual bool upgrade(int& bani, Rucsac& rucsac) = 0;

    int getBonusStamina() const;
    int getBonusReducereScadereStamina() const;
    int getBonusBuzunar() const;
    int getNivel() const;
};

#endif