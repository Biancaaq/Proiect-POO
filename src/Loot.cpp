#include "Loot.hpp"

using namespace std;


Loot::Loot(const std::string& nume, double greutate, int raritate) : Obiect(nume, greutate), raritate(raritate) {}
Loot::~Loot() = default;
