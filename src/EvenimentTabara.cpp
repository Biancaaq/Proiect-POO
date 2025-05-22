#include "EvenimentTabara.hpp"
#include "Mancare.hpp"
#include "Material.hpp"
#include "MemorieLoot.hpp"
#include <iostream>
#include <memory>

using namespace std;


void EvenimentTabara::regenereazaEnergie(Jucator& jucator) {
    int energieMax = jucator.getEnergie();
    jucator.cresteEnergie(energieMax);
    cout << "Ai campat in tabara si ti-ai regenerat energia." << endl;
}

void EvenimentTabara::proceseazaCrafting(Jucator &jucator, const vector<Reteta>& retete, const MemorieLoot& memorie) {
    Rucsac& rucsac = jucator.getRucsac();

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
            for (const auto& [nume, cantitate] : ingrediente) {
                rucsac.consumaLoot(nume, cantitate);
            }

            const string& rez = reteta.getRezultat();
            shared_ptr<Loot> produs = memorie.getMancare(rez);

            if (produs) {
                rucsac.adaugaLoot(produs);
                cout << "Ai craftat: " << produs->getNume() << endl;
            }

            else {
                //TODO: eroare nu s-a gasit obiectul si trebuie tratata exceptia ca nu e spatiu in ghizdan
            }
        }
    }
}

void EvenimentTabara::vindeLoot(Jucator& jucator) {
    Rucsac& rucsac = jucator.getRucsac();

    while (true) {
        cout << "Continutul rucsacului: " << endl;
        rucsac.afiseazaContinut(true);

        cout << "Vrei sa vinzi un item? " << endl;
        cout << "1. Da" << endl;
        cout << "2. Nu" << endl;
        int opt;
        cin >> opt;
        cin.ignore();

        if (opt != 1) {
            break;
        }

        cout << "Introdu indexul itemului pe care vrei sa il vinzi: " << endl;
        int index;
        cin >> index;
        cin.ignore();

        const auto& loot = rucsac.getLoot();
        if (index < 1 || index > (int)loot.size()) {
            //TODO: exceptie index invalid
            continue;
        }

        int pret = loot[index - 1]->getPret();
        jucator.adaugaBani(pret);
        rucsac.aruncaLoot(index);

        cout << "Loot vandut pentru " << pret << " bani." << endl;
    }
}