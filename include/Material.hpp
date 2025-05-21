#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "Loot.hpp"


class Material : public Loot {
    public:
    Material(const std::string& nume, double greutate, int raritate, int pret);
    ~Material() override;

    std::string getNume() const override;
};

#endif