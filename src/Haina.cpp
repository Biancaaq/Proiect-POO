#include "Haina.hpp"


Haina::Haina(const std::string &nume, double greutate, int nivel, int bonusStamina, int bonusViteza, int bonusScadereStamina, double bonusBuzunar) : Obiect(nume, greutate), nivel(nivel), bonusStamina(bonusStamina), bonusViteza(bonusViteza), bonusReducereScadereStamina(bonusScadereStamina), bonusBuzunar(bonusBuzunar) {}
Haina::~Haina() = default;

int Haina::getBonusStamina() const {
    return bonusStamina;
}

int Haina::getBonusViteza() const {
    return bonusViteza;
}

int Haina::getBonusReducereScadereStamina() const {
    return bonusReducereScadereStamina;
}

int Haina::getBonusBuzunar() const {
    return bonusBuzunar;
}
