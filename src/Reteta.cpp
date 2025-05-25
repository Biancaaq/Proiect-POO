#include <fstream>
#include <nlohmann/json.hpp>
#include "DeschidereFisierJSON.hpp"
#include "Reteta.hpp"
#include "Exceptii.hpp"

using json = nlohmann::json;
using namespace std;

Reteta::Reteta(const string& rezultat, const string& tip, const map<string, int>& ingrediente) : rezultat(rezultat), tip(tip), ingrediente(ingrediente) {}

vector<Reteta> Reteta::reteteJson(const string& fisierReteta) {
    vector<Reteta> retete;

    try {
        ifstream inReteta = deschideFisierJson(fisierReteta);
        json jRetete;
        inReteta >> jRetete;

        for (const auto& reteta : jRetete) {
            string rezultat = reteta.at("rezultat");
            string tip = reteta.at("tip");
            map<string, int> ingrediente;

            for (const auto& ingredient : reteta.at("ingrediente")) {
                string nume = ingredient.at("nume");
                int cantitate = ingredient.at("cantitate");
                ingrediente[nume] = cantitate;
            }

            retete.emplace_back(rezultat, tip, ingrediente);
        }
    }

    catch (const exception& e) {
        throw EroareParsingJSON("Eroare la parsarea fisierului de retete.");
    }

    return retete;
}

const map<string, int>& Reteta::getIngrediente() const {
    return ingrediente;
}

const string& Reteta::getRezultat() const {
    return rezultat;
}