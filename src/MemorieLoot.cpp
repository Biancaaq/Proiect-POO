#include <fstream>
#include <random>
#include <iostream>
#include <numeric>
#include "MemorieLoot.hpp"
#include "Mancare.hpp"
#include "Material.hpp"
#include "Jucator.hpp"
#include "Loot.hpp"
#include "Exceptii.hpp"
#include "LootFactory.hpp"

using namespace std;


void MemorieLoot::incarcaLoot() {
    mancare.push_back(LootFactory::mar());
    mancare.push_back(LootFactory::alune_padure());
    mancare.push_back(LootFactory::fructe_padure());
    mancare.push_back(LootFactory::suc_mere());
    mancare.push_back(LootFactory::carne_gatita());
    mancare.push_back(LootFactory::baton_energetic());
    materiale.push_back(LootFactory::piele());
    materiale.push_back(LootFactory::lana());
    materiale.push_back(LootFactory::lemn());
    materiale.push_back(LootFactory::piatra());
    materiale.push_back(LootFactory::clei());
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