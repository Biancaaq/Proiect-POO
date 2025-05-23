#include "EvenimentTabara.hpp"
#include "Mancare.hpp"
#include "Material.hpp"
#include "MemorieLoot.hpp"
#include <iostream>
#include <memory>

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
            cout << "Nu poti crafta nimmic" << endl;
            break;
        }

        cout << "Ce doresti sa craftezi?" << endl;
        for (size_t i = 0; i < craftabile.size(); i++) {
            cout << i + 1 << ". " << craftabile[i]->getRezultat() << endl;
        }

        cout << "0. Inapoi" << endl;

        int opt;
        cin >> opt;
        cin.ignore();

        if (opt == 0) {
            break;
        }

        if (opt < 1 || opt > (int)craftabile.size()) {
            //TODO: eroare
            continue;
        }

        const Reteta& retetaAleasa = *craftabile[opt-1];

        const auto& ingrediente = retetaAleasa.getIngrediente();
        for (const auto& [nume, cantitate] : ingrediente) {
            rucsac.consumaLoot(nume, cantitate);
        }

        shared_ptr<Loot> produsFinal = memorie.getMancare(retetaAleasa.getRezultat());
        if (produsFinal) {
            rucsac.adaugaLoot(produsFinal);
            cout << "Ai craftat: " << produsFinal->getNume() << endl;
        }

        else {
            cout << "Obiectul de craftat nu a fost gasit" << endl;
            //TODO: exceptie reteta invalida
        }
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
        cin.ignore();

        if (opt == 0) {
            break;
        }

        const auto& loot = rucsac.getLoot();
        if (opt < 1 || opt > (int)loot.size()) {
            //TODO: exceptie index invalid
            continue;
        }

        int pret = loot[opt - 1]->getPret();
        jucator.adaugaBani(pret);
        rucsac.aruncaLoot(opt);

        cout << "Loot vandut pentru " << pret << " bani." << endl;
    }
}

void EvenimentTabara::upgradeEchipament(Jucator &jucator) {
    auto& echipamente = jucator.getEchipament();
    cout << "Echipamente disponibile pentru upgrade: " << endl;
    for (size_t i = 0; i < echipamente.size(); ++i) {
        if (!echipamente[i]) {
            cout << "Eroare: echipamentul de la indexul " << i << " este nullptr!" << endl;
            continue;
        }
        cout << i + 1 << ". " << echipamente[i]->getNume() << " (nivel " << echipamente[i]->getNivel() << ")" << endl;
    }

    cout << "Alege echipamentul de upgradat sau 0 pentru a anula: ";
    int alegere;
    cin >> alegere;
    cin.ignore();

    if (alegere < 1 || alegere > (int)echipamente.size()) {;
        return;
    }

    Haina* h = echipamente[alegere - 1];
    jucator.faUpgrade(h->getNume());
}