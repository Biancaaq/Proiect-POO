#include "Loot.hpp"
#include <string>

using namespace std;


int Loot::LootId = 0;

Loot::Loot(const std::string& nume, double greutate, int raritate, int pret) : Obiect(nume, greutate), raritate(raritate), pret(pret), id(++LootId) {}
Loot::~Loot() = default;

int Loot::getRaritate() const {
    return raritate;
}

int Loot::getPret() const {
    return pret;
}

int Loot::getID() const {
    return id;
}