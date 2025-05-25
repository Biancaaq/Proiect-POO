#include <iostream>
#include <map>
#include "Pantofi.hpp"
#include "Exceptii.hpp"

using namespace std;


Pantofi::Pantofi() : Haina("Pantofi", 0.8, 1, 0, 0, 0.0) {}
Pantofi::~Pantofi() = default;

bool Pantofi::upgrade(int& bani, Rucsac& rucsac) {
    if (nivel >= 3) {
        throw EroareUpgrade("Pantofii sunt deja la nivel maxim.");
    }

    int costBani = (nivel == 1 ? 10 : 20);
    map<string, int> materiale;

    if (nivel == 1) {
        materiale["piele"] = 1;
    }

    else if (nivel == 2) {
        materiale["piele"] = 4;
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
    for (auto& [tip, cantitate] : materiale) {
        rucsac.consumaLoot(tip, cantitate);
    }

    nivel++;
    bonusStamina = 5;
    greutate += 0.1;
    cout << "Pantofii au fost upgradati cu succes! Nivel curent: " << nivel << endl;

    return true;
}