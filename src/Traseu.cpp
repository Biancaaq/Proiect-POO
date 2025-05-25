#include <iostream>
#include <random>
#include <vector>
#include "Traseu.hpp"
#include "Jucator.hpp"
#include "Exceptii.hpp"

using namespace std;


Traseu::Traseu() : segmentCurent(0), distantaRamasa(0), pozitieCurenta(0), locatieVizitata(false) {
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

    int numarTabere = 0;
    for (int i = 0; i < 21; ++i) {
        traseu.push_back(TipLocatie::Drum);
        traseu.push_back(TipLocatie::Tabara);
        numarTabere++;

        if (numarTabere == 6 || numarTabere == 13 || numarTabere == 21) {
            traseu.push_back(TipLocatie::Rau);
        }
    }

    traseu.push_back(TipLocatie::OrasFinal);
}

bool Traseu::pas(Jucator& jucator) {
    if (pozitieCurenta >= (int)traseu.size()) {
        throw EroareAplicatie("Pozitie curenta invalida.");
    }

    if (distantaRamasa > 0) {
        distantaRamasa--;
        jucator.consumaEnergie();
        locatieVizitata = false;

        return false;
    }

    pozitieCurenta++;
    locatieVizitata = true;

    if (pozitieCurenta >= (int)traseu.size()) {
        throw JocCastigat("Ai ajuns in oras! Felicitari, ai castigat jocul!");
    }

    TipLocatie locatie = traseu[pozitieCurenta];

    if (locatie == TipLocatie::Rau) {
        cout << "Ai ajuns la un rau!" << endl;
    }

    else if (locatie == TipLocatie::Tabara) {
        cout << "Ai ajuns intr-o tabara!" << endl;
    }

    else if (locatie == TipLocatie::Drum) {
        cout << "Ai ajuns pe un drum!" << endl;
    }

    if (locatie == TipLocatie::Drum) {
        segmentCurent++;

        if (segmentCurent < distanteSegmente.size()) {
            distantaRamasa = distanteSegmente[segmentCurent];
        }

        else {
            distantaRamasa = 0;
        }
    }

    if (traseu[pozitieCurenta] == TipLocatie::Drum && segmentCurent < distanteSegmente.size()) {
        locatieVizitata = false;
    }

    return true;
}

TipLocatie Traseu::getLocatieCurenta() const {
    if (pozitieCurenta < 0 || pozitieCurenta >= (int)traseu.size()) {
        throw EroareAplicatie("Pozitie curenta invalida.");
    }

    return traseu[pozitieCurenta];
}

int Traseu::getNumarRau() const {
    if (pozitieCurenta >= (int)traseu.size()) {
        throw EroareAplicatie("Pozitie curenta invalida.");
    }

    int count = 0;

    for (int i = 0; i <= pozitieCurenta; ++i) {
        if (traseu[i] == TipLocatie::Rau) {
            count++;
        }
    }

    return count;
}