#include "Reteta.hpp"
#include <fstream>
#include <nlohmann/json.hpp>
#include "DeschidereFisierJSON.hpp"

using json = nlohmann::json;
using namespace std;

Reteta::Reteta(const string& rezultat, const string& tip, const map<string, int>& ingrediente) : rezultat(rezultat), tip(tip), ingrediente(ingrediente) {}

vector<Reteta> Reteta::reteteJson(const string& fisierReteta) {
    vector<Reteta> retete;
    ifstream inReteta = deschideFisierJson(fisierReteta);

    json jReteta;
    inReteta >> jReteta;

    for (const auto& reteta : jReteta) {
        string rezultat = reteta["rezultat"];
        string tip = reteta["tip"];
        map<string, int> ingrediente;

        for (const auto& ingredient : reteta["ingrediente"]) {
            string nume = ingredient["nume"];
            int cantitate = ingredient["cantitate"];
            ingrediente[nume] = cantitate;
        }

        retete.emplace_back(rezultat, tip, ingrediente);
    }

    return retete;
}

const map<string, int>& Reteta::getIngrediente() const {
    return ingrediente;
}

const string& Reteta::getRezultat() const {
    return rezultat;
}