#ifndef JUCATOR_HPP
#define JUCATOR_HPP

#include "Rucsac.hpp"
#include "Palarie.hpp"
#include "Bluza.hpp"
#include "Mancare.hpp"
#include "Pantaloni.hpp"
#include "Pantofi.hpp"


class Jucator {
   int energie;
   int bani;
   int viteza;
   int rataReducereScadereEnergie;
   float noroc = 0.0f;

   Rucsac rucsac;
   Palarie palarie;
   Bluza bluza;
   Pantaloni pantaloni;
   Pantofi pantofi;
   // vector de pointeri catre Ob

   public:
   explicit Jucator(int energie = 100, int bani = 0, int viteza = 1, int reducere = 0);
   ~Jucator();

   void faUpgrade(const std::string& numeEchipament);
   void updateStatusuri();
   void adaugaNoroc(float bonus);
   void adaugaBani(int suma);
   void scadeBani(int suma);

   int getViteza() const;
   void consumaEnergie();
   void scadeEnergie(int valoare);
   void cresteEnergie(int valoare);
   void consumaMancare(const Mancare& mancare);
   float getNoroc() const;
   Rucsac& getRucsac();
   int getEnergie() const;
   int getBani() const;
};

#endif