#include "Rucsac.hpp"

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

double Rucsac::getCapacitate() const {
    return capacitate;
}

void Rucsac::setCapacitate(double capacitateNoua) {
    capacitate = capacitateNoua;
}