#include <iostream>
#include "Bluza.hpp"

using namespace std;


Bluza::Bluza() : Haina("Bluza simpla", 1.0, 1, 0, 0, 0, 0.0) {}
Bluza::~Bluza() = default;

void Bluza::upgrade() {
    nivel++;
    bonusStamina += 20;
    cout << "Bluza upgradata cu succes! Nivel curent: " << nivel << endl;
}