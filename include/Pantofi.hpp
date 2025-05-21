#ifndef PANTOFI_HPP
#define PANTOFI_HPP

#include "Haina.hpp"

class Pantofi : public Haina {
public:
    Pantofi();
    ~Pantofi() override;

    void upgrade() override;
};

#endif
