#include <iostream>
#include "Pantofi.hpp"

using namespace std;


Pantofi::Pantofi() : Haina("Pantofi simpli", 0.8, 1, 0, 0, 0, 0.0) {}
Pantofi::~Pantofi() = default;

void Pantofi::upgrade() {
    nivel++;
    bonusViteza += 2;
    cout << "Pantofii au fost upgradati cu succes! Nivel curent: " << nivel << endl;
}
