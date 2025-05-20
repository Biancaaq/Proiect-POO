#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "Loot.hpp"


class Material : public Loot {
    public:
    Material(const std::string& nume, float greutate, int raritate);
    ~Material() override;
};

#endif