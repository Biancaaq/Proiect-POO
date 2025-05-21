#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "Loot.hpp"


class Material : public Loot {
    public:
    Material(const std::string& nume, double greutate, int raritate, const std::string& tip);
    ~Material() override;

    std::string getTip() const override;
};

#endif