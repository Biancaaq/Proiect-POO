#include "Meniu.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


void Meniu::startRun() {
    jucator = Jucator();
    traseu = Traseu();

    while (true) {
        traseu.pas(jucator);

        if (jucator.getEnergie() <= 0) {
            //TODO: exceptie fara energie; game over
        }

        TipLocatie loc = traseu.getLocatieCurenta();

        if (loc == TipLocatie::Drum) {
            drum.executa(jucator, memorie);
        }

        else if (loc == TipLocatie::Tabara) {
            tabara.regenereazaEnergie(jucator);
            tabara.proceseazaCrafting(jucator, retete, memorie);
            tabara.vindeLoot(jucator);
        }

        else if (loc == TipLocatie::Rau) {
            rau.trecereRau(jucator, traseu.getNumarRau());
        }

        else if (loc == TipLocatie::OrasFinal) {
            cout << "Felicitari! Ai ajuns in oras si ai castigat jocul!" << endl;
            break;
        }
    }
}

void Meniu::ruleaza() {
    srand(static_cast<unsigned int>(time(nullptr)));
    memorie.incarcaDinJSON("mancare.json", "materiale.json");
    retete = Reteta::reteteJson("retete.json");

    while (true) {
        cout << "MENIU PRINCIPAL" << endl;
        cout << "1. Start joc nou" << endl;
        cout << "2. Iesire" << endl;
        cout << "Alege o optiune: ";

        int opt;
        cin >> opt;
        cin.ignore();

        switch (opt) {
            case 1: {
                startRun();
                break;
            }

            case 2: {
                cout << "La revedere!" << endl;
                break;
            }

            default: {
                //TODO: exceptie index invalid
                break;
            }
        }
    }

}