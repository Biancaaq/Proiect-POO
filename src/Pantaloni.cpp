#include <iostream>
#include <map>
#include "Pantaloni.hpp"
#include "Exceptii.hpp"

using namespace std;


Pantaloni::Pantaloni() : Haina("Pantaloni", 1.2, 1, 0, 0, 0.0) {}
Pantaloni::~Pantaloni() = default;

bool Pantaloni::upgrade(int& bani, Rucsac& rucsac) {
    if (nivel >= 3) {
        throw EroareUpgrade("Pantalonii sunt deja la nivel maxim.");
    }

    int costBani = (nivel == 1 ? 15 : 20);
    map<std::string, int> materiale;

    if (nivel == 1) {
        materiale["piele"] = 2;
    }

    else if (nivel == 2) {
        materiale["piele"] = 3;
        materiale["lana"] = 1;
    }

    if (bani < costBani) {
        throw EroareBani("Nu ai destui bani pentru a realiza upgradeul.");
    }

    for (const auto& [tip, cantitate] : materiale) {
        if (rucsac.numaraLoot(tip) < cantitate) {
            throw EroareMateriale("Nu ai destule materiale de tip " + tip + " pentru upgrade.");
        }
    }

    bani -= costBani;
    for (const auto& [tip, cantitate] : materiale) {
        rucsac.consumaLoot(tip, cantitate);
    }

    nivel++;
    bonusBuzunar = 2.5;
    greutate += 0.2;
    cout << "Pantalonii au fost upgradati cu succes! Nivel curent: " << nivel << endl;

    return true;
}

void Pantaloni::setNivel2() {
    nivel = 2;
    bonusBuzunar = 2.5;
    greutate += 0.2;
}
