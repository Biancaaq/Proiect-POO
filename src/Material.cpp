#include "Material.hpp"


Material::Material(const std::string& nume, float greutate, int raritate) : Loot(nume, greutate, raritate) {}
Material::~Material() = default;

