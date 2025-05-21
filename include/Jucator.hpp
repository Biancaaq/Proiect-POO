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
   int rataScadereEnergie;
   float noroc = 0.0f;

   Rucsac rucsac;
   Palarie palarie;
   Bluza bluza;
   Pantaloni pantaloni;
   Pantofi pantofi;
   // vector de pointeri catre Ob

   public:
   explicit Jucator(int energie = 100, int bani = 0, int viteza = 1, int scadere = 0);
   ~Jucator();

   void faUpgrade(const std::string& numeEchipament);
   void updateStatusuri();

   void adaugaNoroc(float bonus);
};

#endif