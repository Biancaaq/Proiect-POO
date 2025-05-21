#include "Loot.hpp"

using namespace std;


Loot::Loot(const std::string& nume, double greutate, int raritate, const string& tip) : Obiect(nume, greutate), raritate(raritate), tip(tip) {}
Loot::~Loot() = default;
