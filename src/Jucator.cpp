#include <iostream>
#include <cmath>
#include "Jucator.hpp"

using namespace std;


Jucator::Jucator(int energie, int bani, int viteza, int reducere) : energie(energie), bani(bani), viteza(viteza), rataReducereScadereEnergie(reducere), rucsac(), palarie(), bluza(), pantaloni(), pantofi() {}
Jucator::~Jucator() = default;

void Jucator::faUpgrade(const string& numeEchipament) {
    bool upgradat = false;
    if (numeEchipament == "palarie") {
        upgradat = palarie.upgrade(bani, rucsac);
    }

    else if (numeEchipament == "bluza") {
        upgradat = bluza.upgrade(bani, rucsac);
    }

    else if (numeEchipament == "pantaloni") {
        upgradat = pantaloni.upgrade(bani, rucsac);
    }

    else if (numeEchipament == "pantofi") {
        upgradat = pantofi.upgrade(bani, rucsac);
    }

    if (upgradat) {
        adaugaNoroc(0.00125f);
        cout << "Noroc actual: " << noroc * 100 << "%" << endl;
    }
}

void::Jucator::updateStatusuri() {
    energie = 100 + bluza.getBonusStamina();
    viteza = 1 + pantofi.getBonusViteza();
    rataReducereScadereEnergie = 0 + palarie.getBonusReducereScadereStamina();

    double bonusCapacitate = rucsac.getCapacitate() + pantaloni.getBonusBuzunar();
    rucsac.setCapacitate(bonusCapacitate);
}

void Jucator::adaugaNoroc(float bonus) {
    noroc += bonus;
}

int Jucator::getViteza() const {
    return viteza;
}

void Jucator::consumaEnergie() {
    double greutateLoot = rucsac.getGreutateTotala();
    double greutateRucsac = rucsac.getGreutate();
    double greutateHaine = palarie.getGreutate() + pantaloni.getGreutate() + pantofi.getGreutate() + bluza.getGreutate();
    double greutateTotala = greutateLoot + greutateRucsac + greutateHaine;

    double scadereDeBaza = greutateTotala * 2.0;
    double scadereFinala = scadereDeBaza * (1.0 - rataReducereScadereEnergie / 100.0);

    int scadere = max(1, static_cast<int>(round(scadereFinala)));
    energie -= scadere;

    if (energie < 0 ) {
        energie = 0;
    }
}