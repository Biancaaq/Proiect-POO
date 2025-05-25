#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Meniu.hpp"
#include "Exceptii.hpp"

using namespace std;


void Meniu::startRun() {
    try {
        while (true) {
            bool schimbat = traseu.pas(jucator);

            if (jucator.getEnergie() <= 0) {
                throw EroareEnergie("Ai ramas fara energie! Joc pierdut.");
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

                        if (!cin || optiune < 0 || optiune > 3) {
                            cout << "Optiune invalida. Incearca din nou." << endl;
                            continue;
                        }

                        cin.ignore();

                        switch (optiune) {
                            case 1: {
                                try {
                                    tabara.proceseazaCrafting(jucator, retete, memorie);
                                }

                                catch (const exception& e) {
                                    cout << e.what() << endl;
                                }

                                break;
                            }
                            case 2: {
                                try {
                                    tabara.vindeLoot(jucator);
                                }

                                catch (const exception& e) {
                                    cout << e.what() << endl;
                                }

                                break;
                            }
                            case 0:
                                break;

                            case 3: {
                                try {
                                    tabara.upgradeEchipament(jucator);
                                }

                                catch (const exception& e) {
                                    cout << e.what() << endl;
                                }

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

                while (true) {
                    try {
                        drum.consumaMancareDinRucsac(jucator);

                        break;
                    }

                    catch (const EroareInput& e) {
                        cout << e.what() << endl;
                    }
                }
            }
        }
    }

    catch (const JocCastigat& e) {
        cout << e.what() << endl;
    }

    catch (const EroareEnergie& e) {
        cout << e.what() << endl;
    }

    catch (const EroareInput& e) {
        cout << e.what() << endl;
    }

    catch (const EroareBani& e) {
        cout << e.what() << endl;
        exit(0);
    }

    catch (...) {
        cout << "Eroare necunoscuta." << endl;
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

        if (!cin || (opt != 1 && opt != 2)) {
            cout << "Optiune invalida. Incearca din nou." << endl << endl;
            continue;
        }

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
        }
    }
}