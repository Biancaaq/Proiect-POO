#ifndef SUPER_JUCATOR_HPP
#define SUPER_JUCATOR_HPP

#include <vector>
#include "Haina.hpp"
#include "Jucator.hpp"
#include "Bonus.hpp"


class SuperJucator {
    Bonus<int> energieMaxima;
    Bonus<int> baniInitiali;
    Bonus<int> rataScadereEnergie;
    Bonus<float> noroc;

    std::vector<Haina*> echipament;

    public:
    SuperJucator();
    SuperJucator(int energieMaxima, int baniInitiali, int rataScadereEnergie, float noroc);
    SuperJucator(const SuperJucator& alt);
    SuperJucator& operator=(const SuperJucator& alt);
    ~SuperJucator();

    friend std::ostream& operator<<(std::ostream& out, const SuperJucator& s);
    friend std::istream& operator>>(std::istream& in, SuperJucator& s);
    SuperJucator& operator++();
    explicit operator Jucator() const;
    friend bool operator==(const SuperJucator& s, const Jucator& j);

    int getEnergieMaxima() const;
    int getBaniInitiali() const;
    int getRataScadereEnergie() const;
    float getNoroc() const;

    void limiteazaStatusuri();
};

#endif