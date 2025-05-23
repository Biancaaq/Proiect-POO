#include "EvenimentRau.hpp"
#include <iostream>

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
            //TODO: exceptie rau invalid
            break;
        }
    }

    cout << "Pentru a-l traversa, ai nevoie de " << cost << " bani." << endl;
    cout << "Ai strans " << jucator.getBani() << endl;

    if (jucator.getBani() >= cost) {
        jucator.scadeBani(cost);

        cout << "Ai trecut raul cu succes." << endl;
    }

    else {
        cout << "Insuficienti bani. Ai pierdut." << endl;
        exit(0);
        //TODO: exceptie insuficienti bani, game over
    }
}