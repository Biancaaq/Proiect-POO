#ifndef RETETA_HPP
#define RETETA_HPP

#include <map>
#include <string>
#include <vector>

class Reteta {
    std::string rezultat;
    std::string tip;
    std::map<std::string, int> ingrediente;

public:
    Reteta(const std::string& rezultat, const std::string& tip, const std::map<std::string, int>& ingrediente);

    const std::map<std::string, int>& getIngrediente() const;
    const std::string& getRezultat() const;

    static std::vector<Reteta> reteteJson(const std::string& fisierRetete);
};

#endif