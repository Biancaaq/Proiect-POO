#include <iostream>
#include <map>
#include "Palarie.hpp"
#include "Exceptii.hpp"

using namespace std;


Palarie::Palarie() : Haina("Palarie", 0.6, 1, 0, 0, 0.0) {}
Palarie::~Palarie() = default;

bool Palarie::upgrade(int& bani, Rucsac& rucsac) {
    if (nivel >= 3) {
        throw EroareUpgrade("Palaria este deja la nivel maxim.");
    }

    int costBani = (nivel == 1 ? 10 : 15);
    map<std::string, int> materiale;

    if (nivel == 1) {
        materiale["piele"] = 1;
    }

    else if (nivel == 2) {
        materiale["lana"] = 2;
    }

    if (bani < costBani) {
        throw EroareBani("Nu ai destui bani pentru a realiza upgradeul.");
    }

    for (const auto& [tip, cantitate] : materiale) {
        if (rucsac.numaraLoot(tip) < cantitate) {
            throw EroareMateriale("Nu ai suficiente materiale de tip " + tip + " pentru upgrade.");
        }
    }

    bani -= costBani;
    for (const auto& [tip, cantitate] : materiale) {
        rucsac.consumaLoot(tip, cantitate);
    }

    nivel++;
    bonusReducereScadereStamina = 1;
    greutate += 0.1;
    cout << "Palaria a fost upgradata cu succes! Nivel curent: " << nivel << endl;

    return true;
}