#include "Material.hpp"


Material::Material(const std::string& nume, double greutate, int raritate) : Loot(nume, greutate, raritate) {}
Material::~Material() = default;

