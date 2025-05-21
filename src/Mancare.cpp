#include "Mancare.hpp"

using namespace std;


Mancare::Mancare(const string& nume, double greutate, int raritate, const string& tip, int energie, bool procesata) : Loot(nume, greutate, raritate, tip), energieRecuperata(energie), procesata(procesata) {}
Mancare::~Mancare() = default;

string Mancare::getTip() const {
    return tip;
}
