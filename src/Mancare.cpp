#include "Mancare.hpp"

Mancare::Mancare(const std::string& nume, double greutate, int raritate, int energie) : Loot(nume, greutate, raritate), energieRecuperata(energie) {}
Mancare::~Mancare() = default;
