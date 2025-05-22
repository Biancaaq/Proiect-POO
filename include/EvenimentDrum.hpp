#ifndef EVENIMENTDRUM_HPP
#define EVENIMENTDRUM_HPP

#include "Eveniment.hpp"


class EvenimentDrum : public Eveniment {
public:
    void executa(Jucator& jucator, const MemorieLoot& memorie) override;
    void interactLoot(Jucator& jucator, std::shared_ptr<Loot> loot);
};

#endif
