#include "Traseu.hpp"
#include "Jucator.hpp"
#include <iostream>
#include <random>
#include <vector>

using namespace std;


Traseu::Traseu() : segmentCurent(0), distantaRamasa(0), pozitieCurenta(0) {
    genereazaDistante();
    genereazaTraseu();
    distantaRamasa = distanteSegmente[0];
}

void Traseu::genereazaDistante() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(2, 4);

    distanteSegmente.clear();
    for (int i = 0; i < 21; ++i) {
        distanteSegmente.push_back(dist(gen));
    }
}

void Traseu::genereazaTraseu() {
    traseu.clear();

    for (int i = 0; i < 21; ++i) {
        traseu.push_back(TipLocatie::Drum);
        traseu.push_back(TipLocatie::Tabara);

        if (i == 5 || i == 12 || i == 20) {
            traseu.push_back(TipLocatie::Rau);
        }
    }

    traseu.push_back(TipLocatie::OrasFinal);
}

void Traseu::pas(Jucator& jucator) {
    int viteza = jucator.getViteza();
    distantaRamasa -= viteza;
    jucator.consumaEnergie();

    if (distantaRamasa <= 0) {
        pozitieCurenta++;
        if (pozitieCurenta >= (int)traseu.size()) {
            cout << "Ai ajuns in oras!" << endl;

            return;
        }

        TipLocatie locatie = traseu[pozitieCurenta];

        if (locatie == TipLocatie::Rau) {
            cout << "Ai ajuns la un rau!" << endl;
        }

        else if (locatie == TipLocatie::Tabara) {
            cout << "Ai ajuns intr-o tabara!" << endl;
        }

        segmentCurent++;
        if (segmentCurent < distanteSegmente.size()) {
            distantaRamasa = distanteSegmente[segmentCurent];
        }
    }
}

TipLocatie Traseu::getLocatieCurenta() const {
    if (pozitieCurenta >= 0 && pozitieCurenta < (int)traseu.size()) {
        return traseu[pozitieCurenta];
    }

    return TipLocatie::OrasFinal;
}

int Traseu::getNumarRau() const {
    int count = 0;

    for (int i = 0; i <= pozitieCurenta; ++i) {
        if (traseu[i] == TipLocatie::Rau) {
            count++;
        }
    }

    return count;
}