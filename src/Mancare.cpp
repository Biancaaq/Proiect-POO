#include "Mancare.hpp"

using namespace std;


Mancare::Mancare(const string& nume, double greutate, int raritate, int pret, int energie, bool procesata) : Loot(nume, greutate, raritate, pret), energieRecuperata(energie), procesata(procesata) {}
Mancare::~Mancare() = default;

int Mancare::getEnergieRecuperata() const {
    return energieRecuperata;
}

bool Mancare::getProcesata() const {
    return procesata;
}