#ifndef PANTOFI_HPP
#define PANTOFI_HPP

#include "Haina.hpp"

class Pantofi : public Haina {
public:
    Pantofi();
    ~Pantofi() override;

    bool upgrade(int& bani, Rucsac& rucsac) override;
};

#endif
