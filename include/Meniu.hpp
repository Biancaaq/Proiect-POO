#ifndef MENIU_HPP
#define MENIU_HPP

#include "Jucator.hpp"
#include "MemorieLoot.hpp"
#include "Reteta.hpp"
#include "EvenimentDrum.hpp"
#include "EvenimentTabara.hpp"
#include "EvenimentRau.hpp"
#include "Traseu.hpp"
#include <vector>


class Meniu {
    Jucator jucator;
    MemorieLoot memorie;
    std::vector<Reteta> retete;
    EvenimentDrum drum;
    EvenimentTabara tabara;
    EvenimentRau rau;
    Traseu traseu;

    void startRun();

    public:
    void ruleaza();
};

#endif