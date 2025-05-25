#ifndef EVENIMENTDRUM_HPP
#define EVENIMENTDRUM_HPP

#include "Eveniment.hpp"


class EvenimentDrum : public Eveniment {
public:
    void executa(Jucator& jucator, const MemorieLoot& memorie);
    void interactLoot(Jucator& jucator, std::shared_ptr<Loot> loot);
    void aruncaLoot(Jucator& jucator);
    void consumaMancareDinRucsac(Jucator& jucator);
};

#endif
