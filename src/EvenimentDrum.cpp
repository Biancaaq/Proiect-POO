#include <iostream>
#include <random>
#include "EvenimentDrum.hpp"

#include "Mancare.hpp"
#include "MemorieLoot.hpp"

using namespace std;


void EvenimentDrum::interactLoot(Jucator& jucator, std::shared_ptr<Loot> loot) {
    cout << "Ai gasit: " << loot->getNume() << " (greutate: " << loot->getGreutate() << " kg)" << endl;
    cout << "Vrei sa il iei?" << endl;
    cout << "1. Da" << endl;
    cout << "2. Nu" << endl;
    int rasp;
    cin >> rasp;
    cin.ignore();

    if (rasp == 2) {
        cout << "Vrei sa arunci ceva din rucsac?" << endl;
        cout << "1. Da" << endl;
        cout << "2. Nu" << endl;
        cin >> rasp;
        cin.ignore();

        if (rasp == 1) {
            jucator.getRucsac().afiseazaContinut(true);
            cout << "Indexul obiectului de aruncat: ";
            int index;
            cin >> index;
            cin.ignore();

            if (jucator.getRucsac().aruncaLoot(index)) {
                cout << "Obiectul a fost aruncat." << endl;
            }
        }

        cout << "Ai lasat loot-ul." << endl;
        return;
    }

    if (jucator.getRucsac().incapeInRucsac(loot)) {
        jucator.getRucsac().adaugaLoot(loot);
        cout << "Loot adaugat in rucsac." << endl;
    }

    else {
        shared_ptr<Mancare> mancare = dynamic_pointer_cast<Mancare>(loot);
        if (mancare) {
            cout << mancare->getNume() << " nu incape in rucsac. Vrei sa o mananci acum?" << endl;
            cout << "1. Da" << endl;
            cout << "2. Nu" << endl;

            int opt;
            cin >> opt;
            cin.ignore();

            if (opt == 1) {
                jucator.consumaMancare(*mancare);
                return;
            }
        }

        cout << "Vrei sa arunci ceva?" << endl;
        cout << "1. Da" << endl;
        cout << "2. Nu" << endl;
        cin >> rasp;
        cin.ignore();
        if (rasp == 1) {
            while (true) {
                jucator.getRucsac().afiseazaContinut(true);
                cout << "Introdu indexul obiectului de aruncat sau 0 daca te-ai razgandit: " << endl;
                int index;
                cin >> index;
                cin.ignore();

                if (index == 0) {
                    break;
                }

                if (jucator.getRucsac().aruncaLoot(index)) {
                    cout << "Obiectul a fost aruncat." << endl;
                    if (jucator.getRucsac().incapeInRucsac(loot)) {
                        jucator.getRucsac().adaugaLoot(loot);
                        cout << "Loot adaugat in rucsac." << endl;
                        return;
                    }

                    else {
                        cout << "Inca nu este suficient spatiu. Mai vrei sa arunci ceva?" << endl;
                        cout << "1. Da" << endl;
                        cout << "2. Nu" << endl;
                        cin >> rasp;
                        cin.ignore();
                        if (rasp == 2) break;
                    }
                }
            }
            cout << "Nu ai putut adauga lootul. L-ai lasat in urma." << endl;
        }

        else {
            cout << "Ai lasat lootul." << endl;
        }
    }
}


void EvenimentDrum::executa(Jucator& jucator, const MemorieLoot& memorie) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> sansaLoot(1, 100);

    if (sansaLoot(gen) <= 70) {
        shared_ptr<Loot> lootGasit = memorie.genereazaLootAleator(jucator);
        interactLoot(jucator, lootGasit);
    }

    uniform_int_distribution<int> sansaIepure(1, 100);
    if (sansaIepure(gen) <= 10) {
        cout << "Un iepure ti-a aparut in cale!" << endl;
        cout << "Incerci sa il vanezi?" << endl;
        cout << "1. Da" << endl;
        cout << "2. Nu" << endl;

        int opt;
        cin >> opt;
        cin.ignore();

        if (opt == 1) {
            jucator.scadeEnergie(3);

            uniform_int_distribution<int> sansaSucces(1, 100);
            if (sansaSucces(gen) <= 50) {
                cout << "Vanatoarea a avut succes! Ai primit x1 carne de iepure." << endl;
                shared_ptr<Loot> carne = make_shared<Mancare>("carne de iepure", 0.4, 3, 12, 25, false);
                interactLoot(jucator, carne);
            }

            else {
                cout << "Iepurele a scapat." << endl;
            }
        }
    }
}

