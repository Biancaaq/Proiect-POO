#ifndef TRASEU_HPP
#define TRASEU_HPP

#include <vector>


enum class TipLocatie {
    Drum,
    Tabara,
    Rau,
    OrasFinal
};

class Jucator;

class Traseu {
    std::vector<int> distanteSegmente;
    std::vector<TipLocatie> traseu;
    int segmentCurent;
    int distantaRamasa;

    public:
    Traseu();
    void genereazaDistante();
    void genereazaTraseu();
    void pas(Jucator& jucator);
};

#endif
