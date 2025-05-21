#include "Material.hpp"

using namespace std;


Material::Material(const std::string& nume, double greutate, int raritate, const string& tip) : Loot(nume, greutate, raritate, tip) {}
Material::~Material() = default;

string Material::getTip() const {
    return tip;
}