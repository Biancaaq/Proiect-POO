#ifndef EVENIMENT_TABARA_HPP
#define EVENIMENT_TABARA_HPP

#include "Jucator.hpp"
#include "Eveniment.hpp"
#include "Reteta.hpp"
#include "MemorieLoot.hpp"

class EvenimentTabara : public Eveniment{
    public:
    void regenereazaEnergie(Jucator& jucator);
    void proceseazaCrafting(Jucator& jucator, const std::vector<Reteta>& retete, const MemorieLoot& memorie);
    void vindeLoot(Jucator& jucator);
};

#endif