#include <iostream>
#include "Pantaloni.hpp"

using namespace std;


Pantaloni::Pantaloni() : Haina("Pantaloni simpli", 1.2, 1, 0, 0, 0, 0.0) {}
Pantaloni::~Pantaloni() = default;

void Pantaloni::upgrade() {
    nivel++;
    bonusBuzunar += 5.0;
    cout << "Pantalonii au fost upgradati cu succes! Nivel curent: " << nivel << endl;
}