#include "LootFactory.hpp"
#include <stdexcept>

using namespace std;
using json = nlohmann::json;

shared_ptr<Loot> LootFactory::creeaza(const string& tip, const json& ob) {
    if (tip == "mancare") {
        return make_shared<Mancare>(ob["nume"], ob["greutate"], ob["raritate"], ob["pret"], ob["energie"], ob["procesata"]);
    }

    else if (tip == "material") {
        return make_shared<Material>(ob["nume"], ob["greutate"], ob["raritate"], ob["pret"]);
    }

    else {
        throw invalid_argument("Tip necunoscut in LootFactory.");
    }
}
