#ifndef RUCSAC_HPP
#define RUCSAC_HPP

#include <memory>
#include "Obiect.hpp"
#include "Loot.hpp"
#include <vector>


class Rucsac : public Obiect {
    protected:
    int nivel;
    double capacitate;

    std::vector<std::shared_ptr<Loot>> loot;

    public:
    explicit Rucsac(const std::string& nume = "Rucsac simplu", double greutate = 1.5, int nivel = 1, double capacitate = 10.0);
    ~Rucsac() override;

    int numaraLoot(const std::string& tip) const;
    bool consumaLoot(const std::string& tip, int cantitate);
    void adaugaLoot(std::shared_ptr<Loot>& obiect);
    bool incapeInRucsac(const std::shared_ptr<Loot>& obiect) const;
    void afiseazaContinut(bool index = false) const;
    bool aruncaLoot(int index);

    double getCapacitate() const;
    void setCapacitate(double capacitateNoua);
    double getGreutateTotala() const;
    const std::vector<std::shared_ptr<Loot>>& getLoot() const;
};

#endif