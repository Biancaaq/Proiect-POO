#include <iostream>
#include <map>
#include "Pantofi.hpp"

using namespace std;


Pantofi::Pantofi() : Haina("Pantofi", 0.8, 1, 0, 0, 0.0) {}
Pantofi::~Pantofi() = default;

bool Pantofi::upgrade(int& bani, Rucsac& rucsac) {
    cout << "am ajuns aici" << endl;
    if (nivel >= 3) {
        cout << "Pantofii sunt deja la nivel maxim." << endl;
        return false;
    }

    cout << "am ajuns aici x2" << endl;

    int costBani = (nivel == 1 ? 10 : 20);
    map<string, int> materiale;

    if (nivel == 1) {
        materiale["piele"] = 1;
    }

    else if (nivel == 2) {
        materiale["piele"] = 4;
    }

    cout << "am ajuns aici x3" << endl;

    bool ok1 = true;
    if (bani < costBani) {
        cout << "Nu ai destui bani." << endl;

        ok1 = false;
    }

    cout << "am ajuns aici x4" << endl;

    bool ok2 = true;
    for (const auto& [tip, cantitate] : materiale) {
        if (rucsac.numaraLoot(tip) < cantitate) {
            cout << "Nu ai suficienta piele." << endl;

            ok2 = false;
        }
    }

    if (ok1 == false || ok2 == false) {
        return false;
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