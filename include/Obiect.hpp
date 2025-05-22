#ifndef OBIECT_HPP
#define OBIECT_HPP

#include <string>


class Obiect {
    protected:
    std::string nume;
    double greutate;

    public:
    Obiect(const std::string& nume, double greutate);
    virtual ~Obiect();

    virtual double getGreutate() const = 0;

};

#endif