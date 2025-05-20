#include "Mancare.hpp"

Mancare::Mancare(const std::string& nume, float greutate, int raritate, int energie) : Loot(nume, greutate, raritate), energieRecuperata(energie) {}
Mancare::~Mancare() = default;
