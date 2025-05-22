#ifndef EVENIMENT_HPP
#define EVENIMENT_HPP

#include "Jucator.hpp"
#include "MemorieLoot.hpp"


class Eveniment {
    public:
    virtual void executa(Jucator& jucator, const MemorieLoot& memorie) = 0;
    virtual ~Eveniment() = default;
};

#endif