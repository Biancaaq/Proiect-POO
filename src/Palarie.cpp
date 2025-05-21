#include <iostream>
#include "Palarie.hpp"

using namespace std;


Palarie::Palarie() : Haina("Palarie simpla", 0.6, 1, 0, 0, 0, 0.0) {}
Palarie::~Palarie() = default;

void Palarie::upgrade() {
    nivel++;
    bonusScadereStamina += 1;
    cout << "Palaria a fost upgradata cu succes! Nivel curent: " << nivel << endl;

}