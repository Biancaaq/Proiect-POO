#ifndef JUCATOR_HPP
#define JUCATOR_HPP

#include "Rucsac.hpp"
#include "Palarie.hpp"
#include "Bluza.hpp"
#include "Pantaloni.hpp"
#include "Pantofi.hpp"


class Jucator {
   int energie;
   int bani;
   int viteza;

   Rucsac rucsac;
   Palarie palarie;
   Bluza bluza;
   Pantaloni pantaloni;
   Pantofi pantofi;

   public:
   Jucator(int energie = 100, int bani = 0, int viteza = 1);
   ~Jucator();
};

#endif