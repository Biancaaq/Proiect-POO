#ifndef JUCATOR_HPP
#define JUCATOR_HPP

#include "Rucsac.hpp"
#include "Bluza.hpp"
#include "Mancare.hpp"


class Jucator {
   int energie;
   int bani;
   int rataReducereScadereEnergie;
   float noroc;
   bool bonusSuperJucator = false;

   Rucsac rucsac;
   std::vector<Haina*> echipament;

   public:
   explicit Jucator(int energie = 100, int bani = 0, int reducere = 0, float noroc = 0.0f);
   ~Jucator();
   Jucator(const Jucator&);
   Jucator& operator=(const Jucator&);

   void faUpgrade(const std::string& numeEchipament);
   void updateStatusuri();
   void adaugaNoroc(float bonus);
   void adaugaBani(int suma);
   void scadeBani(int suma);

   void consumaEnergie();
   void scadeEnergie(int valoare);
   void cresteEnergie(int valoare);
   void consumaMancare(const Mancare& mancare);
   void recupereazaEnergie();

   float getNoroc() const;
   Rucsac& getRucsac();
   int getEnergie() const;
   int getBani() const;
   int getRataScadereEnergie() const;
   const std::vector<Haina*>& getEchipament() const;
   std::vector<Haina*>& getEchipament();

   void setBonusSuperJucator(bool bonus);
   bool areBonusSuperJucator() const;
};

#endif