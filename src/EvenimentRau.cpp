#include <iostream>
#include "EvenimentRau.hpp"
#include "Exceptii.hpp"

using namespace std;


void EvenimentRau::trecereRau(Jucator& jucator, int numarRau) {
    int cost = 0;

    switch (numarRau) {
        case 1: {
            cost = 70;
            break;
        }

        case 2: {
            cost = 140;
            break;
        }

        case 3: {
            cost = 230;
            break;
        }

        default: {
            throw EroareInput("Numarul raului este invalid. Acesta poate fi 1, 2 sau 3.");
        }
    }

    cout << "Pentru a-l traversa, ai nevoie de " << cost << " bani." << endl;
    cout << "Ai strans " << jucator.getBani() << endl;

    if (jucator.getBani() >= cost) {
        jucator.scadeBani(cost);
        cout << "Ai trecut raul cu succes." << endl << endl;
    }

    else {
        throw EroareBani("Nu ai suficienti bani pentru a trece raul. Ai pierdut jocul.");
    }
}