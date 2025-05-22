#include "Material.hpp"

using namespace std;


Material::Material(const std::string& nume, double greutate, int raritate, int pret) : Loot(nume, greutate, raritate, pret) {}
Material::~Material() = default;