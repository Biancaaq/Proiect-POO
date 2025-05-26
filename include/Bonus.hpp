#ifndef BONUS_HPP
#define BONUS_HPP


template <typename T>
class Bonus {
    T valoare;

public:
    Bonus() : valoare(0) {}
    explicit Bonus(T valoare) : valoare(valoare) {}

    operator T() const {
        return valoare;
    }
};

#endif
