#include <iostream>
#include <map>
#include "Palarie.hpp"

using namespace std;


Palarie::Palarie() : Haina("Palarie simpla", 0.6, 1, 0, 0, 0, 0.0) {}
Palarie::~Palarie() = default;

bool Palarie::upgrade(int& bani, Rucsac& rucsac) {
    if (nivel >= 3) {
        cout << "Palaria este deja la nivel maxim." << endl;

        return false;
    }

    int costBani = (nivel == 1 ? 10 : 15);
    map<std::string, int> materiale;

    if (nivel == 1) {
        materiale["piele"] = 1;
    }

    else if (nivel == 2) {
        materiale["lana"] = 2;
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
    bonusScadereStamina += 1;
    cout << "Palaria a fost upgradata cu succes! Nivel curent: " << nivel << endl;

    return true;
}