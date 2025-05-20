#ifndef OBIECT_HPP
#define OBIECT_HPP

#include <string>


class Obiect {
    protected:
    std::string nume;
    float greutate;

    public:
    Obiect(const std::string& nume, float greutate);
    virtual ~Obiect();

};

#endif