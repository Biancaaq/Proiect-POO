#include "Loot.hpp"
#include <string>

using namespace std;


Loot::Loot(const std::string& nume, double greutate, int raritate, int pret) : Obiect(nume, greutate), raritate(raritate), pret(pret) {}
Loot::~Loot() = default;

int Loot::getRaritate() const {
    return raritate;
}

int Loot::getPret() const {
    return pret;
}