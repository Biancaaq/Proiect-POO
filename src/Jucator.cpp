#include <iostream>
#include "Jucator.hpp"

using namespace std;


Jucator::Jucator(int energie, int bani, int viteza, int scadere) : energie(energie), bani(bani), viteza(viteza), rataScadereEnergie(energie), rucsac(), palarie(), bluza(), pantaloni(), pantofi() {}
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
    rataScadereEnergie = 0 + palarie.getBonusScadereStamina();

    double bonusCapacitate = rucsac.getCapacitate() + pantaloni.getBonusBuzunar();
    rucsac.setCapacitate(bonusCapacitate);
}

void Jucator::adaugaNoroc(float bonus) {
    noroc += bonus;
}