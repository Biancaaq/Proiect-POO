#include <iostream>
#include <random>
#include "EvenimentDrum.hpp"
#include "Mancare.hpp"
#include "MemorieLoot.hpp"
#include "Exceptii.hpp"

using namespace std;


void EvenimentDrum::interactLoot(Jucator& jucator, shared_ptr<Loot> loot) {
    if (!loot) {
        throw EroarePointerNull("Lootul primit este null.");
    }

    cout << "Ai gasit: " << loot->getNume() << ", greutate: " << loot->getGreutate() << " kg" << ", raritate: " << loot->getRaritate() << endl << endl;

    int rasp;

    while (true) {
        try {
            cout << "Vrei sa il iei?" << endl;
            cout << "1. Da" << endl;
            cout << "2. Nu" << endl;

            cin >> rasp;

            if (rasp == -1) {
                exit(0);
            }

            if (!cin || (rasp != 1 && rasp != 2)) {
                throw EroareInput("Optiune invalida.");
            }

            cin.ignore();

            break;
        }

        catch (const EroareInput& e) {
            cout << e.what() << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    if (rasp == 2) {
        while (true) {
            try {
                aruncaLoot(jucator);
                break;
            }

            catch (const EroareInput& e) {
                cout << e.what() << endl;

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        cout << "Ai lasat lootul." << endl << endl;

        return;

    }

    if (jucator.getRucsac().incapeInRucsac(loot)) {
        jucator.getRucsac().adaugaLoot(loot);
        cout << "Loot adaugat in rucsac." << endl << endl;

        while (true) {
            try {
                aruncaLoot(jucator);
                break;
            }

            catch (const EroareInput& e) {
                cout << e.what() << endl;

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        return;
    }

    shared_ptr<Mancare> mancare = dynamic_pointer_cast<Mancare>(loot);

    if (mancare) {
        while (true) {
            cout << mancare->getNume() << " nu incape in rucsac. Vrei sa o mananci acum?" << endl;
            cout << "1. Da" << endl;
            cout << "2. Nu" << endl;

            int opt;
            cin >> opt;

            if (opt == -1) {
                exit(0);
            }

            if (!cin || (opt != 1 && opt != 2)) {
                cout << "Optiune invalida. Incearca din nou." << endl;

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                continue;
            }

            cin.ignore();

            if (opt == 1) {
                jucator.consumaMancare(*mancare);

                return;
            }
        }
    }

    while (true) {
        try {
            aruncaLoot(jucator);

            if (jucator.getRucsac().incapeInRucsac(loot)) {
                jucator.getRucsac().adaugaLoot(loot);
                cout << "Loot adaugat in rucsac." << endl << endl;

                return;
            }

            cout << "Inca nu este suficient spatiu. Mai vrei sa arunci ceva?" << endl;
            cout << "1. Da" << endl;
            cout << "2. Nu" << endl;

            int opt;
            cin >> opt;

            if (opt == -1) {
                exit(0);
            }

            if (!cin || (opt != 1 && opt != 2)) {
                throw EroareInput("Optiune invalida.");
            }

            cin.ignore();

            if (opt == 2) {
                cout << "Ai lasat lootul." << endl << endl;

                return;
            }
        }

        catch (const EroareInput& e) {
            cout << e.what() << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}


void EvenimentDrum::executa(Jucator& jucator, const MemorieLoot& memorie) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> sansaLoot(1, 100);

    if (sansaLoot(gen) <= 100) {
        shared_ptr<Loot> lootGasit = memorie.genereazaLootAleator(jucator);
        interactLoot(jucator, lootGasit);
    }

    uniform_int_distribution<int> sansaIepure(1, 100);
    if (sansaIepure(gen) <= 30) {
        cout << "Un iepure ti-a aparut in cale!" << endl;

        int opt;

        while (true) {
            try {
                cout << "Incerci sa il vanezi?" << endl;
                cout << "1. Da" << endl;
                cout << "2. Nu" << endl;

                cin >> opt;

                if (opt == -1) {
                    exit(0);
                }

                if (!cin || (opt != 1 && opt != 2)) {
                    throw EroareInput("Optiune invalida.");
                }

                cin.ignore();
                break;
            }

            catch (const EroareInput& e) {
                cout << e.what() << endl;

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        if (opt == 1) {
            jucator.scadeEnergie(3);

            uniform_int_distribution<int> sansaSucces(1, 100);

            if (sansaSucces(gen) <= 50) {
                cout << "Vanatoarea a avut succes! Ai primit x1 carne de iepure." << endl;
                shared_ptr<Loot> carne = make_shared<Mancare>("carne de iepure", 0.4, 3, 12, 25, false);
                interactLoot(jucator, carne);
            }

            else {
                cout << "Iepurele a scapat." << endl << endl;
            }
        }
    }
}

void EvenimentDrum::aruncaLoot(Jucator& jucator) {
    const auto& rucsac = jucator.getRucsac();

    while (true) {
        cout << "Vrei sa arunci ceva din rucsac?" << endl;
        cout << "1. Da" << endl;
        cout << "2. Nu" << endl;

        int rasp;
        cin >> rasp;

        if (rasp == -1) {
            exit(0);
        }

        if (!cin || (rasp != 1 && rasp != 2)) {
            throw EroareInput("Optiune invalida.");
        }

        cin.ignore();

        if (rasp == 2) {
            return;
        }

        if (rasp == 1) {
            if (rucsac.getLoot().empty()) {
                cout << "Rucsacul este gol. Nu ai ce arunca." << endl;

                return;
            }

            rucsac.afiseazaContinut(true);
            cout << "Indexul obiectului de aruncat sau '0' daca doresti sa anulezi actiunea: ";

            int index;
            cin >> index;

            if (index == -1) {
                exit(0);
            }

            if (!cin || index < 0 || index > (int)rucsac.getLoot().size()) {
                throw EroareInput("Optiune invalida.");
            }

            cin.ignore();

            if (index == 0) {
                cout << "Actiune anulata." << endl << endl;
                return;
            }

            if (jucator.getRucsac().aruncaLoot(index)) {
                cout << "Obiectul a fost aruncat." << endl << endl;
            }

            if (jucator.getRucsac().getLoot().empty()) {
                cout << "Rucsacul este acum gol." << endl << endl;
                return;
            }
        }
    }
}

void EvenimentDrum::consumaMancareDinRucsac(Jucator& jucator) {
    cout << "Energie ramasa: " << jucator.getEnergie() << endl;

    while (true) {
        cout << "Vrei sa consumi mancare din rucsac?" << endl;
        cout << "1. Da" << endl;
        cout << "2. Nu" << endl;

        int alegere;
        cin >> alegere;

        if (alegere == -1) {
            exit(0);
        }

        if (!cin || (alegere != 1 && alegere != 2)) {
            throw EroareInput("Optiune invalida.");
        }

        cin.ignore();

        if (alegere == 2) {
            return;
        }

        break;
    }

    const auto& loot = jucator.getRucsac().getLoot();
    vector<shared_ptr<Mancare>> mancareDisponibila;

    for (const auto& item : loot) {
        auto m = dynamic_pointer_cast<Mancare>(item);

        if (m) {
            mancareDisponibila.push_back(m);
        }
    }

    if (mancareDisponibila.empty()) {
        cout << "Nu ai mancare in rucsac." << endl << endl;
        return;
    }

    cout << "Mancare disponibila pentru consum:" << endl;

    for (size_t i = 0; i < mancareDisponibila.size(); ++i) {
        cout << i + 1 << ". " << mancareDisponibila[i]->getNume() << " (+" << mancareDisponibila[i]->getEnergieRecuperata() << " energie, " << "greutate: " << mancareDisponibila[i]->getGreutate() << ")" << endl;
    }

    cout << "0. Renunta" << endl;

    int opt;
    cout << "Alege mancarea de consumat: ";
    cin >> opt;

    if (opt == -1) {
        exit(0);
    }

    if (!cin || opt < 0 || opt > (int)mancareDisponibila.size()) {
        throw EroareInput("Optiune invalida.");
    }

    cin.ignore();

    if (opt == 0) {
        cout << "Nu ai consumat nimic." << endl << endl;

        return;
    }

    shared_ptr<Mancare> aleasa = mancareDisponibila[opt - 1];

    jucator.consumaMancare(*aleasa);
    jucator.getRucsac().consumaLoot(aleasa->getNume(), 1);

    cout << "Ai consumat cu succes " << aleasa->getNume() << "." << endl;
    cout << "Energie noua: " << jucator.getEnergie() << endl << endl;
}
