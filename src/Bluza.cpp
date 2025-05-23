#include <iostream>
#include <map>
#include "Bluza.hpp"

using namespace std;


Bluza::Bluza() : Haina("Bluza", 1.0, 1, 0, 0, 0.0) {}
Bluza::~Bluza() = default;

bool Bluza::upgrade(int& bani, Rucsac& rucsac) {
    if (nivel >= 3) {
        cout << "Bluza este deja la nivel maxim." << endl;

        return false;
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
    for (const auto& [tip, cantitate] : materiale) {
        rucsac.consumaLoot(tip, cantitate);
    }


    nivel++;
    bonusStamina = 20;
    greutate += 0.2;
    cout << "Bluza upgradata cu succes! Nivel curent: " << nivel << endl;

    return true;
}