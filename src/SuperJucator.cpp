#include <iostream>
#include "SuperJucator.hpp"
#include "Exceptii.hpp"
#include "Palarie.hpp"
#include "Pantaloni.hpp"
#include "Pantofi.hpp"
#include "Bluza.hpp"

using namespace std;


SuperJucator::SuperJucator() : energieMaxima(0), baniInitiali(0), rataScadereEnergie(0), noroc(0.0f) {
    echipament.push_back(new Palarie());
    echipament.push_back(new Bluza());
    echipament.push_back(new Pantaloni());
    echipament.push_back(new Pantofi());
}

SuperJucator::SuperJucator(int energie, int bani, int rata, float noroc) : energieMaxima(energie), baniInitiali(bani), rataScadereEnergie(rata), noroc(noroc) {
    echipament.push_back(new Palarie());
    echipament.push_back(new Bluza());
    echipament.push_back(new Pantaloni());
    echipament.push_back(new Pantofi());

    limiteazaStatusuri();
}

SuperJucator::SuperJucator(const SuperJucator& sjuc) : energieMaxima(sjuc.energieMaxima), baniInitiali(sjuc.baniInitiali), rataScadereEnergie(sjuc.rataScadereEnergie), noroc(sjuc.noroc) {
    for (auto* h : sjuc.echipament) {
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
    }
}

SuperJucator::~SuperJucator() {
    for (auto* h : echipament) {
        delete h;
    }
}

SuperJucator& SuperJucator::operator=(const SuperJucator& sjuc) {
    if (this != &sjuc) {
        for (auto* h : echipament) {
            delete h;
        }

        echipament.clear();

        energieMaxima = sjuc.energieMaxima;
        baniInitiali = sjuc.baniInitiali;
        rataScadereEnergie = sjuc.rataScadereEnergie;
        noroc = sjuc.noroc;

        for (auto* h : sjuc.echipament) {
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
        }
    }
    return *this;
}

ostream& operator<<(ostream& out, const SuperJucator& s) {
    out << "SuperJucator cu bonusurile: energie maxima - " << s.energieMaxima << ", bani initiali - " << s.baniInitiali << ", rata de scadere a energie - " << s.rataScadereEnergie << ", noroc: " << s.noroc * 100 << endl;

    for (const auto* h : s.echipament) {
        out << " - " << h->getNume() << " (nivel: " << h->getNivel() << ")" << endl;
    }

    return out;
}

istream& operator>>(istream& in, SuperJucator& s) {
    int energie = 0, bani = 0, rata = 0;
    float noroc = 0.0f;

    cout << "Introdu energie maxima (max 150): ";
    in >> energie;

    if (energie == -1) {
        exit(0);
    }

    if (!cin || energie <= 0) {
        throw EroareInput("Date invalide.");
    }

    cout << "Introdu bani initiali (max 100): ";
    in >> bani;

    if (bani == -1) {
        exit(0);
    }

    if (!cin || bani <= 0) {
        throw EroareInput("Date invalide.");
    }

    cout << "Introdu rata scadere energie (max 3): ";
    in >> rata;

    if (rata == -1) {
        exit(0);
    }

    if (!cin || rata <= 0) {
        throw EroareInput("Date invalide.");
    }

    cout << "Introdu noroc (0.0 - 0.5): ";
    in >> noroc;

    if (noroc == -1) {
        exit(0);
    }

    if (!cin || noroc <= 0.0) {
        throw EroareInput("Date invalide.");
    }

    s.energieMaxima = Bonus<int>(energie);
    s.baniInitiali = Bonus<int>(bani);
    s.rataScadereEnergie = Bonus<int>(rata);
    s.noroc = Bonus<float>(noroc);

    for (auto* h : s.echipament) {
        int lvl;
        cout << "Introdu nivel pentru " << h->getNume() << " (1 sau 2): ";
        in >> lvl;

        if (lvl == -1) {
            exit(0);
        }

        if (lvl != 1 && lvl != 2)
            throw EroareInput("Nivelul hainei trebuie sa fie 1 sau 2.");

        if (lvl == 2) {
            h->setNivel2();
        }
    }

    s.limiteazaStatusuri();

    return in;
}

SuperJucator& SuperJucator::operator++() {
    energieMaxima = Bonus<int>(static_cast<int>(energieMaxima) + 50);
    baniInitiali = Bonus<int>((int)baniInitiali + 50);
    rataScadereEnergie = Bonus<int>((int)rataScadereEnergie + 1);
    noroc = Bonus<float>((float)noroc + 0.005f);

    limiteazaStatusuri();

    return *this;
}

bool operator==(const SuperJucator& s, const Jucator& j) {
    return s.getEnergieMaxima() == j.getEnergie() && s.getBaniInitiali() == j.getBani() && s.getRataScadereEnergie() == j.getRataScadereEnergie() && abs(s.getNoroc() - j.getNoroc()) < 0.001f;
}

SuperJucator::operator Jucator() const {
    Jucator j(100 + energieMaxima, baniInitiali, rataScadereEnergie, noroc);

    for (size_t i = 0; i < echipament.size(); ++i) {
        delete j.getEchipament()[i];

        if (echipament[i]->getNume() == "Palarie") {
            j.getEchipament()[i] = new Palarie(*dynamic_cast<Palarie*>(echipament[i]));
        }

        else if (echipament[i]->getNume() == "Bluza") {
            j.getEchipament()[i] = new Bluza(*dynamic_cast<Bluza*>(echipament[i]));
        }

        else if (echipament[i]->getNume() == "Pantaloni") {
            j.getEchipament()[i] = new Pantaloni(*dynamic_cast<Pantaloni*>(echipament[i]));
        }

        else if (echipament[i]->getNume() == "Pantofi") {
            j.getEchipament()[i] = new Pantofi(*dynamic_cast<Pantofi*>(echipament[i]));
        }
    }

    return j;
}


int SuperJucator::getEnergieMaxima() const {
    return energieMaxima;
}

int SuperJucator::getBaniInitiali() const {
    return baniInitiali;
}

int SuperJucator::getRataScadereEnergie() const {
    return rataScadereEnergie;
}

float SuperJucator::getNoroc() const {
    return noroc;
}

void SuperJucator::limiteazaStatusuri() {
    if ((int)energieMaxima > 150) {
        energieMaxima = Bonus<int>(150);
    }

    if ((int)baniInitiali > 100) {
        baniInitiali = Bonus<int>(100);
    }

    if ((int)rataScadereEnergie > 3) {
        rataScadereEnergie = Bonus<int>(3);
    }

    if ((float)noroc > 0.5f) {
        noroc = Bonus<float>(0.5f);
    }
}
