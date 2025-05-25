#include <iostream>
#include <memory>
#include <limits>
#include <cmath>
#include "EvenimentTabara.hpp"
#include "Mancare.hpp"
#include "Material.hpp"
#include "MemorieLoot.hpp"
#include "Exceptii.hpp"

using namespace std;


void EvenimentTabara::regenereazaEnergie(Jucator& jucator) {
    jucator.recupereazaEnergie();
    cout << "Ai campat in tabara si ti-ai regenerat energia." << endl;
}

void EvenimentTabara::proceseazaCrafting(Jucator &jucator, const vector<Reteta>& retete, const MemorieLoot& memorie) {
    Rucsac& rucsac = jucator.getRucsac();

    while (true) {
        vector<const Reteta*> craftabile;

        for (const auto& reteta : retete) {
            const auto& ingrediente = reteta.getIngrediente();
            bool suficienteIngrediente = true;

            for (const auto& [nume, cantitate] : ingrediente) {
                if (rucsac.numaraLoot(nume) < cantitate) {
                    suficienteIngrediente = false;

                    break;
                }
            }

            if (suficienteIngrediente) {
                craftabile.push_back(&reteta);
            }
        }

        if (craftabile.empty()) {
            cout << "Nu poti crafta nimmic" << endl << endl;
            break;
        }

        cout << "Ce doresti sa craftezi?" << endl;
        for (size_t i = 0; i < craftabile.size(); i++) {
            cout << i + 1 << ". " << craftabile[i]->getRezultat() << endl;
        }

        cout << "0. Inapoi" << endl;

        int opt;
        cin >> opt;

        if (!cin || opt < 0 || opt > (int)craftabile.size()) {
            throw EroareInput("Optiune invalida.");
        }

        cin.ignore();

        if (opt == 0) {
            break;
        }

        const Reteta& retetaAleasa = *craftabile[opt-1];
        for (const auto& [nume, cantitate] : retetaAleasa.getIngrediente()) {
            rucsac.consumaLoot(nume, cantitate);
        }

        shared_ptr<Loot> produsFinal = memorie.getMancare(retetaAleasa.getRezultat());
        if (!produsFinal) {
            throw EroareMateriale("Obiectul craftat nu a fost gasit in memorie.");
        }

        rucsac.adaugaLoot(produsFinal);
        cout << "Ai craftat: " << produsFinal->getNume() << endl << endl;

        break;
    }
}

void EvenimentTabara::vindeLoot(Jucator& jucator) {
    Rucsac& rucsac = jucator.getRucsac();

    while (true) {
        cout << "Continutul rucsacului: " << endl;
        rucsac.afiseazaContinut(true);

        cout << "Alege itemul pe care vrei sa il vinzi sau '0' pentru inapoi: " << endl;
        int opt;
        cin >> opt;

        if (!cin || opt < 0 || opt > (int)rucsac.getLoot().size()) {
            throw EroareInput("Index invalid pentru loot.");
        }

        cin.ignore();

        if (opt == 0) {
            break;
        }

        int pret = rucsac.getLoot()[opt - 1]->getPret();

        if (jucator.areBonusSuperJucator()) {
            pret += 5;
        }

        jucator.adaugaBani(pret);
        rucsac.aruncaLoot(opt);

        cout << "Loot vandut pentru " << pret << " bani." << endl << endl;

        break;
    }
}

void EvenimentTabara::upgradeEchipament(Jucator &jucator) {
    const auto& echipamente = jucator.getEchipament();

    cout << "Noroc actual: " << jucator.getNoroc() << endl << endl;
    cout << "Echipamente disponibile pentru upgrade: " << endl;

    for (size_t i = 0; i < echipamente.size(); ++i) {
        if (!echipamente[i]) {
            throw EroarePointerNull("Echipamentul de la indexul " + to_string(i) + " este null.");
        }

        cout << i + 1 << ". " << echipamente[i]->getNume() << " (nivel " << echipamente[i]->getNivel() << ")" << endl;
    }

    cout << "Alege echipamentul de upgradat sau 0 pentru a anula: ";
    int alegere;
    cin >> alegere;


    if (!cin || alegere < 0 || alegere > (int)echipamente.size()) {
        throw EroareInput("Optiune invalida.");
    }

    if (alegere == 0) {
        return;
    }

    const Haina* h = echipamente[alegere - 1];

    if (!h) {
        throw EroarePointerNull("Echipamentul selectat este nullptr.");
    }

    jucator.faUpgrade(h->getNume());
}