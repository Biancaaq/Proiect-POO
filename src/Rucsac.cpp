#include <iostream>
#include <algorithm>
#include "Rucsac.hpp"
#include "Exceptii.hpp"
#include "Loot.hpp"

using namespace std;


Rucsac::Rucsac(const std::string& nume, double greutate, int nivel, double capacitate) : Obiect(nume, greutate), nivel(nivel), capacitate(capacitate) {}
Rucsac::~Rucsac() = default;

int Rucsac::numaraLoot(const string& tip) const {
    int total = 0;

    for (const auto& l : loot) {
        if (l->getNume() == tip) {
            total++;
        }
    }

    return total;
}

bool Rucsac::consumaLoot(const string& tip, int cantitate) {
    int cnt = 0;

    for (auto i = loot.begin(); i != loot.end() && cnt < cantitate;) {
        if ((*i)->getNume() == tip) {
            i = loot.erase(i);
            cnt++;
        }

        else {
            ++i;
        }
    }

    if (cnt != cantitate) {
        throw EroareMateriale("Nu ai suficiente materiale de tip '" + tip + "'.");
    }

    return true;
}

void Rucsac::adaugaLoot(std::shared_ptr<Loot>& obiect) {
    if (!obiect) {
        throw EroarePointerNull("Obiectul adaugat este null.");
    }

    if (!incapeInRucsac(obiect)) {
        throw EroareInput("Obiectul nu incape in rucsac.");
    }

    loot.push_back(obiect);

    sort(loot.begin(), loot.end(), [](const shared_ptr<Loot>& a, const shared_ptr<Loot>& b) {return a->getPret() > b->getPret();});
}

bool Rucsac::incapeInRucsac(const std::shared_ptr<Loot>& obiect) const {
    if (!obiect) {
        throw EroarePointerNull("Obiectul este null.");
    }

    return getGreutateTotala() + obiect->getGreutate() <= capacitate;
}

void Rucsac::afiseazaContinut(bool index) const {
    if (loot.empty()) {
        cout << "Rucsacul este gol." << endl << endl;
        return;
    }

    for (size_t i = 0; i < loot.size(); ++i) {
        if (index) {
            cout << i + 1 << ". ";
        }

        cout << loot[i]->getNume() << " (greutate: " << loot[i]->getGreutate() << ", id: " << loot[i]->getID() << ")" << endl;
    }
}

bool Rucsac::aruncaLoot(int index) {
    if (loot.empty()) {
        throw EroareRucsacGol("Rucsacul este gol.");
    }

    if (index == -1) {
        exit(0);
    }

    if (index < 1 || index > static_cast<int>(loot.size())) {
        throw EroareInput("Index invalid.");
    }

    loot.erase(loot.begin() + (index - 1));
    return true;
}

double Rucsac::getCapacitate() const {
    return capacitate;
}

void Rucsac::setCapacitate(double capacitateNoua) {
    capacitate = capacitateNoua;
}

double Rucsac::getGreutateTotala() const {
    double total = 0.0;

    for (const auto& l : loot) {
        if (l) {
            total += l->getGreutate();
        }
    }

    return total;
}

const vector<shared_ptr<Loot>>& Rucsac::getLoot() const {
    return loot;
}