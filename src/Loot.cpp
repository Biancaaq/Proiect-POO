#include "Loot.hpp"

using namespace std;


Loot::Loot(const std::string& nume, float greutate, int raritate) : Obiect(nume, greutate) {}
Loot::~Loot() = default;
