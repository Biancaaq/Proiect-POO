#include <iostream>
#include <map>
#include "Bluza.hpp"
#include "Exceptii.hpp"

using namespace std;


Bluza::Bluza() : Haina("Bluza", 1.0, 1, 0, 0, 0.0) {}
Bluza::~Bluza() = default;

bool Bluza::upgrade(int& bani, Rucsac& rucsac) {
    if (nivel >= 3) {
        throw EroareUpgrade("Bluza este deja la nivel maxim.");
    }

    int costBani = (nivel == 1 ? 15 : 20);
    map<string, int> materiale;

    if (nivel == 1) {
        materiale["piele"] = 2;
    }

    else if (nivel == 2) {
        materiale["piele"] = 2;
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
    bonusStamina = 20;
    greutate += 0.2;
    cout << "Bluza upgradata cu succes! Nivel curent: " << nivel << endl;

    return true;
}