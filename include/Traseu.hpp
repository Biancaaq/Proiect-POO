#ifndef TRASEU_HPP
#define TRASEU_HPP

#include <vector>
#include <cstddef>


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
    size_t segmentCurent;
    int distantaRamasa;
    int pozitieCurenta;
    bool locatieVizitata;

    public:
    Traseu();
    void genereazaDistante();
    void genereazaTraseu();
    bool pas(Jucator& jucator);

    TipLocatie getLocatieCurenta() const;
    int getNumarRau() const;

    void setLocatieVizitata(bool vizitata);
};

#endif
