#include "Haina.hpp"


Haina::Haina(const std::string &nume, double greutate, int nivel, int bonusStamina, int bonusViteza, int bonusScadereStamina, double bonusBuzunar) : Obiect(nume, greutate), nivel(nivel), bonusStamina(bonusStamina), bonusViteza(bonusViteza), bonusScadereStamina(bonusScadereStamina), bonusBuzunar(bonusBuzunar) {}
Haina::~Haina() = default;

bool Haina::upgrade(int& bani, Rucsac& rucsac) {}