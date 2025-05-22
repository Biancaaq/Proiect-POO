#include "Mancare.hpp"

using namespace std;


Mancare::Mancare(const string& nume, double greutate, int raritate, int pret, int energie) : Loot(nume, greutate, raritate, pret), energieRecuperata(energie) {}
Mancare::~Mancare() = default;

int Mancare::getEnergieRecuperata() const {
    return energieRecuperata;
}