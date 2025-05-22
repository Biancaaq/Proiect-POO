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

    double getGreutate() const;
    const std::string& getNume() const;

};

#endif