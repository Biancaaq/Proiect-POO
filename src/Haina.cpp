#include "Haina.hpp"


Haina::Haina(const std::string &nume, double greutate, int nivel, int bonusStamina, int bonusViteza, int bonusScadereStamina, double bonusBuzunar) : Obiect(nume, greutate), nivel(nivel), bonusStamina(bonusStamina), bonusViteza(bonusViteza), bonusScadereStamina(bonusScadereStamina), bonusBuzunar(bonusBuzunar) {}
Haina::~Haina() = default;

int Haina::getBonusStamina() const {
    return bonusStamina;
}

int Haina::getBonusViteza() const {
    return bonusViteza;
}

int Haina::getBonusScadereStamina() const {
    return bonusScadereStamina;
}

int Haina::getBonusBuzunar() const {
    return bonusBuzunar;
}
