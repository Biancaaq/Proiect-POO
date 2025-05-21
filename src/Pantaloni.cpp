#include <iostream>
#include <map>
#include "Pantaloni.hpp"

using namespace std;


Pantaloni::Pantaloni() : Haina("Pantaloni simpli", 1.2, 1, 0, 0, 0, 0.0) {}
Pantaloni::~Pantaloni() = default;

bool Pantaloni::upgrade(int& bani, Rucsac& rucsac) {
    if (nivel >= 3) {
        std::cout << "Pantalonii sunt deja la nivel maxim." << endl;

        return false;
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

    bool ok1 = true;
    if (bani < costBani) {
        cout << "Nu ai destui bani." << endl;

        ok1 = false;
    }

    bool ok2 = true;
    for (const auto& [tip, cantitate] : materiale) {
        if (rucsac.numaraLoot(tip) < cantitate) {
            cout << "Nu ai destule materiale de tip " << tip << "." << endl;

            ok2 = false;
        }
    }

    if (ok1 == false || ok2 == false) {
        return false;
    }

    bani -= costBani;
    for (const auto& [tip, cantitate] : materiale)
        rucsac.consumaLoot(tip, cantitate);

    nivel++;
    bonusBuzunar += 5.0;
    cout << "Pantalonii au fost upgradati cu succes! Nivel curent: " << nivel << endl;

    return true;
}