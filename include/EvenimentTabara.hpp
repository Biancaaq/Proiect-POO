#ifndef EVENIMENT_TABARA_HPP
#define EVENIMENT_TABARA_HPP

#include "Jucator.hpp"
#include "Reteta.hpp"
#include "MemorieLoot.hpp"

class EvenimentTabara {
    public:
    void regenereazaEnergie(Jucator& jucator);
    void proceseazaCrafting(Jucator& jucator, const std::vector<Reteta>& retete, const MemorieLoot& memorie);
    void vindeLoot(Jucator& jucator);
    void upgradeEchipament(Jucator& jucator);
};

#endif