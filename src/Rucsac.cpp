#include <iostream>
#include "Rucsac.hpp"

using namespace std;


Rucsac::Rucsac(const std::string& nume, double greutate, int nivel, double capacitate) : Obiect(nume, greutate), nivel(nivel), capacitate(capacitate) {}
Rucsac::~Rucsac() = default;
