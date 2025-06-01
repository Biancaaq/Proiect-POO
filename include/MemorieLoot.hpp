#ifndef MEMORIE_LOOT_HPP
#define MEMORIE_LOOT_HPP

#include <vector>
#include <memory>
#include "Loot.hpp"
#include "Jucator.hpp"


class MemorieLoot {
    std::vector<std::shared_ptr<Loot>> mancare;
    std::vector<std::shared_ptr<Loot>> materiale;

public:
    void incarcaLoot();
    std::shared_ptr<Loot> genereazaLootAleator(const Jucator& jucator) const;
    std::shared_ptr<Mancare> getMancare(const std::string& nume) const;
};

#endif
