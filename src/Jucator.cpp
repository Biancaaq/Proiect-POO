#include <iostream>
#include "Jucator.hpp"

using namespace std;


Jucator::Jucator(int energie, int bani, int viteza) : energie(energie), bani(bani), viteza(viteza), rucsac(), palarie(), bluza(), pantaloni(), pantofi() {}
Jucator::~Jucator() = default;

void Jucator::faUpgrade(const string& numeEchipament) {
    if (numeEchipament == "palarie") {
        palarie.upgrade(bani, rucsac);
    }

    else if (numeEchipament == "bluza") {
        bluza.upgrade(bani, rucsac);
    }

    else if (numeEchipament == "pantaloni") {
        pantaloni.upgrade(bani, rucsac);
    }

    else if (numeEchipament == "pantofi") {
        pantofi.upgrade(bani, rucsac);
    }
}