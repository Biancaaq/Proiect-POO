#include "Mancare.hpp"

using namespace std;


Mancare::Mancare(const string& nume, double greutate, int raritate, int pret, int energie, bool procesata) : Loot(nume, greutate, raritate, pret), energieRecuperata(energie), procesata(procesata) {}
Mancare::~Mancare() = default;

string Mancare::getNume() const {
    return nume;
}

double Mancare::getGreutate() const {
    return greutate;
}