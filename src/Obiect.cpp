#include "Obiect.hpp"

using namespace std;


Obiect::Obiect(const string &nume, double greutate) : nume(nume), greutate(greutate) {}
Obiect::~Obiect() = default;

double Obiect::getGreutate() const {
    return greutate;
}

string Obiect::getNume() const {
    return nume;
}