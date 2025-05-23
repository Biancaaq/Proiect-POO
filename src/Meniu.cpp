#include "Meniu.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;


void Meniu::startRun() {
    jucator = Jucator();

    while (true) {
        bool schimbat = traseu.pas(jucator);

        if (jucator.getEnergie() <= 0) {
            //TODO: exceptie fara energie; game over
        }

        TipLocatie loc = traseu.getLocatieCurenta();

        if (schimbat) {
            if (loc == TipLocatie::Tabara) {
                tabara.regenereazaEnergie(jucator);

                int optiune = -1;
                while (optiune != 0) {
                    cout << "Esti in tabara. Ce vrei sa faci?" << endl;
                    cout << "1. Crafting" << endl;
                    cout << "2. Vinde loot" << endl;
                    cout << "3. Upgrade" << endl;
                    cout << "0. Continua calatoria" << endl;
                    cout << "Alege: ";
                    cin >> optiune;
                    cin.ignore();

                    switch (optiune) {
                        case 1: {
                            tabara.proceseazaCrafting(jucator, retete, memorie);
                            break;
                        }
                        case 2: {
                            tabara.vindeLoot(jucator);
                            break;
                        }
                        case 0:
                            break;
                        case 3: {
                            tabara.upgradeEchipament(jucator);

                            break;

                        }

                        default: {
                            cout << "Optiune invalida. Incearca din nou." << endl;
                            break;
                        }
                    }
                }
            }

            else if (loc == TipLocatie::Rau) {
                rau.trecereRau(jucator, traseu.getNumarRau());
            }
        }

        else if (loc == TipLocatie::Drum) {
            drum.executa(jucator, memorie);
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
                exit(0);
            }

            default: {
                //TODO: exceptie index invalid
                break;
            }
        }
    }

}