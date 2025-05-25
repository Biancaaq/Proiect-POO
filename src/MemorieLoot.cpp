#include <fstream>
#include <random>
#include <nlohmann/json.hpp>
#include <iostream>
#include "MemorieLoot.hpp"
#include "Mancare.hpp"
#include "Material.hpp"
#include "Jucator.hpp"
#include "Loot.hpp"
#include "DeschidereFisierJSON.hpp"
#include "Exceptii.hpp"

using json = nlohmann::json;
using namespace std;


void MemorieLoot::incarcaDinJSON(const string &fisierMancare, const string &fisierMateriale) {
    ifstream inMancare = deschideFisierJson(fisierMancare);

    if (!inMancare.is_open()) {
        throw EroareParsingJSON("Nu s-a putut deschide fisierul de mancare");
    }

    json jMancare;
    inMancare >> jMancare;

    for (const auto& m : jMancare) {
        string nume = m["nume"];
        double greutate = m["greutate"];
        int raritate = m["raritate"];
        int energie = m["energie"];
        int pret = m["pret"];
        bool procesata = m["procesata"];

        mancare.push_back(make_shared<Mancare>(nume, greutate, raritate, pret, energie, procesata));
    }


    ifstream inMateriale = deschideFisierJson(fisierMateriale);

    if (!inMateriale.is_open()) {
        throw EroareParsingJSON("Nu s-a putut deschide fisierul de materiale");
    }

    json jMateriale;
    inMateriale >> jMateriale;

    for (const auto& m : jMateriale) {
        string nume = m["nume"];
        double greutate = m["greutate"];
        int raritate = m["raritate"];
        int pret = m["pret"];

        materiale.push_back(make_shared<Material>(nume, greutate, raritate, pret));
    }
}

shared_ptr<Loot> MemorieLoot::genereazaLootAleator(const Jucator &jucator) const {
    vector<shared_ptr<Loot>> LootTotal;

    for (const auto& m : mancare) {
        auto mPtr = dynamic_pointer_cast<Mancare>(m);

        if (mPtr && !mPtr->getProcesata()) {
            LootTotal.push_back(mPtr);
        }
    }

    LootTotal.insert(LootTotal.end(), materiale.begin(), materiale.end());

    if (LootTotal.empty()) {
        throw EroarePointerNull("Nu exista loot disponibil pentru generare.");
    }

    vector<double> sanse;
    for (const auto& l : LootTotal) {
        int raritate = l->getRaritate();
        float noroc = jucator.getNoroc();

        double sansa = (1.0 / (1.0 + raritate)) * (1.0 + noroc);
        sanse.push_back(sansa);
    }

    double total = accumulate(sanse.begin(), sanse.end(), 0.0);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(0.0, total);

    double nr = dist(gen);
    double cumulata = 0.0;

    for (size_t i = 0; i < LootTotal.size(); i++) {
        cumulata += sanse[i];

        if (nr <= cumulata) {
            return LootTotal[i];
        }
    }

    throw EroarePointerNull("Nu s-a putut genera niciun loot.");
}

shared_ptr<Mancare> MemorieLoot::getMancare(const string& nume) const {
    for (const auto& m : mancare) {
        auto mancarePtr = dynamic_pointer_cast<Mancare>(m);

        if (mancarePtr && mancarePtr->getNume() == nume) {
            return make_shared<Mancare>(*mancarePtr);
        }
    }

    return nullptr;
}