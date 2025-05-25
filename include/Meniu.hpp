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

    Meniu();
    Meniu(const Meniu&) = delete;
    Meniu& operator=(const Meniu&) = delete;

    void startRun();
    void initializareJucator();

    public:
    static Meniu& getInstanta();
    void ruleaza();
};

#endif