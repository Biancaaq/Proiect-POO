#include <iostream>
#include <cmath>
#include "Jucator.hpp"
#include "Exceptii.hpp"

using namespace std;


Jucator::Jucator(int energie, int bani, int reducere) : energie(energie), bani(bani), rataReducereScadereEnergie(reducere) {
    echipament.push_back(new Palarie());
    echipament.push_back(new Bluza());
    echipament.push_back(new Pantaloni());
    echipament.push_back(new Pantofi());
}

Jucator::~Jucator() {
    for (auto* e : echipament) {
        delete e;
    }
}

Jucator::Jucator(const Jucator& j) : energie(j.energie), bani(j.bani), rataReducereScadereEnergie(j.rataReducereScadereEnergie), noroc(j.noroc), rucsac(j.rucsac) {
    for (auto* h : j.echipament) {
        if (h->getNume() == "Palarie") {
            echipament.push_back(new Palarie(*dynamic_cast<Palarie*>(h)));
        }

        else if (h->getNume() == "Bluza") {
            echipament.push_back(new Bluza(*dynamic_cast<Bluza*>(h)));
        }

        else if (h->getNume() == "Pantaloni") {
            echipament.push_back(new Pantaloni(*dynamic_cast<Pantaloni*>(h)));
        }

        else if (h->getNume() == "Pantofi") {
            echipament.push_back(new Pantofi(*dynamic_cast<Pantofi*>(h)));
        }

        else {
            echipament.push_back(nullptr);
        }
    }
}

Jucator& Jucator::operator=(const Jucator& other) {
    if (this != &other) {
        for (auto* h : echipament)
            delete h;
        echipament.clear();

        energie = other.energie;
        bani = other.bani;
        rataReducereScadereEnergie = other.rataReducereScadereEnergie;
        noroc = other.noroc;
        rucsac = other.rucsac;

        for (auto* h : other.echipament) {
            if (h->getNume() == "Palarie") {
                echipament.push_back(new Palarie(*dynamic_cast<Palarie*>(h)));
            }

            else if (h->getNume() == "Bluza") {
                echipament.push_back(new Bluza(*dynamic_cast<Bluza*>(h)));
            }

            else if (h->getNume() == "Pantaloni") {
                echipament.push_back(new Pantaloni(*dynamic_cast<Pantaloni*>(h)));
            }

            else if (h->getNume() == "Pantofi") {
                echipament.push_back(new Pantofi(*dynamic_cast<Pantofi*>(h)));
            }

            else {
                echipament.push_back(nullptr);
            }
        }
    }

    return *this;
}


void Jucator::faUpgrade(const string& numeEchipament) {
    bool upgradat = false;
    if (numeEchipament == "Palarie") {
        upgradat = echipament[0]->upgrade(bani, rucsac);
    }

    else if (numeEchipament == "Bluza") {
        upgradat = echipament[1]->upgrade(bani, rucsac);
    }

    else if (numeEchipament == "Pantaloni") {
        upgradat = echipament[2]->upgrade(bani, rucsac);
    }

    else if (numeEchipament == "Pantofi") {
        upgradat = echipament[3]->upgrade(bani, rucsac);
    }

    else {
        throw EroareInput("Numele echipamentului este invalid.");
    }

    if (upgradat) {
        adaugaNoroc(0.00125f);
        cout << "Noroc actual: " << noroc * 100 << "%" << endl;
    }
}

void::Jucator::updateStatusuri() {
    for (auto* h : echipament) {
        if (!h) throw EroarePointerNull("Echipament null.");
    }

    energie = 100 + echipament[1]->getBonusStamina();
    rataReducereScadereEnergie = 0 + echipament[0]->getBonusReducereScadereStamina();

    double bonusCapacitate = rucsac.getCapacitate() + echipament[2]->getBonusBuzunar();
    rucsac.setCapacitate(bonusCapacitate);
}

void Jucator::adaugaNoroc(float bonus) {
    noroc += bonus;
}

void Jucator::consumaEnergie() {
    double greutateLoot = rucsac.getGreutateTotala();
    double greutateRucsac = rucsac.getGreutate();
    double greutateHaine = 0.0;

    for (const auto* h : echipament) {
        if (!h) {
            throw EroarePointerNull("Echipament null.");
        }

        greutateHaine += h->getGreutate();
    }

    double greutateTotala = greutateLoot + greutateRucsac + greutateHaine;

    double scadereDeBaza = greutateTotala * 2.0;
    double scadereFinala = scadereDeBaza * (1.0 - rataReducereScadereEnergie / 100.0);

    int scadere = max(1, static_cast<int>(round(scadereFinala)));
    energie -= scadere;

    if (energie < 0 ) {
        energie = 0;
        throw EroareEnergie("Ai ramas fara energie! Joc pierdut.");
    }
}

void Jucator::scadeEnergie(int valoare) {
    energie -= valoare;

    if (energie < 0) {
        energie = 0;
        throw EroareEnergie("Ai ramas fara energie! Joc pierdut.");
    }
}

void Jucator::cresteEnergie(int valoare) {
    energie += valoare;
}

void Jucator::recupereazaEnergie() {
    energie = 100 + echipament[1]->getBonusStamina();
}

void Jucator::consumaMancare(const Mancare& mancare) {
    cresteEnergie(mancare.getEnergieRecuperata());
    cout << "Ai consumat " << mancare.getNume() << ", (procesata: " << mancare.getProcesata() << ") si ai regenerat " << mancare.getEnergieRecuperata() << " energie." << endl;
}

float Jucator::getNoroc() const {
    return noroc;
}

Rucsac& Jucator::getRucsac() {
    return rucsac;
}

int Jucator::getEnergie() const {
    return energie;
}

int Jucator::getBani() const {
    return bani;
}

void Jucator::adaugaBani(int suma) {
    bani += suma;
}

void Jucator::scadeBani(int suma) {
    if (suma > bani) {
        throw EroareBani("Nu ai suficienti bani pentru aceasta actiune.");
    }

    bani -= suma;
}

const vector<Haina*>& Jucator::getEchipament() const {
    return echipament;
}