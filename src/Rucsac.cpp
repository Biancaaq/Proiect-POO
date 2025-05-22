#include "Rucsac.hpp"
#include <iostream>

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
    return cnt == cantitate;
}

void Rucsac::adaugaLoot(std::shared_ptr<Loot>& obiect) {
    loot.push_back(obiect);
}

bool Rucsac::incapeInRucsac(const std::shared_ptr<Loot>& obiect) const {
    return getGreutateTotala() + obiect->getGreutate() <= capacitate;
}

void Rucsac::afiseazaContinut(bool index) const {
    if (loot.empty()) {
        cout << "Rucsacul este gol." << endl;
        return; //TODO: exceptie rucsac gol
    }

    for (size_t i = 0; i < loot.size(); ++i) {
        if (index) cout << i + 1 << ". ";
        cout << loot[i]->getNume() << " (greutate: " << loot[i]->getGreutate() << ")" << endl;
    }
}

bool Rucsac::aruncaLoot(int index) {
    if (index < 1 || index > (int)loot.size()) {
        cout << "Index invalid." << endl; //TODO: exceptie
        return false;
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