#include "Haina.hpp"


Haina::Haina(const std::string &nume, double greutate, int nivel, int bonusStamina, int bonusScadereStamina, double bonusBuzunar) : Obiect(nume, greutate), nivel(nivel), bonusStamina(bonusStamina), bonusReducereScadereStamina(bonusScadereStamina), bonusBuzunar(bonusBuzunar) {}
Haina::~Haina() = default;

int Haina::getBonusStamina() const {
    return bonusStamina;
}

int Haina::getBonusReducereScadereStamina() const {
    return bonusReducereScadereStamina;
}

int Haina::getBonusBuzunar() const {
    return bonusBuzunar;
}

int Haina::getNivel() const {
    return nivel;
}