#include "LootFactory.hpp"

using namespace std;


shared_ptr<Mancare> LootFactory::mar() {
    return make_shared<Mancare>("mar", 0.2, 0, 4, 10, false);
}

shared_ptr<Mancare> LootFactory::alune_padure() {
    return make_shared<Mancare>("alune de padure", 0.1, 2, 6, 8, false);
}

shared_ptr<Mancare> LootFactory::fructe_padure() {
    return make_shared<Mancare>("fructe de padure", 0.15, 1, 5, 7, false);
}

shared_ptr<Mancare> LootFactory::suc_mere() {
    return make_shared<Mancare>("suc de mere", 0.3, 1, 12, 20, true);
}

shared_ptr<Mancare> LootFactory::carne_gatita() {
    return make_shared<Mancare>("carne gatita", 0.45, 4, 20, 40, true);
}

shared_ptr<Mancare> LootFactory::baton_energetic() {
    return make_shared<Mancare>("baton energetic", 0.6, 3, 22, 40, true);
}

shared_ptr<Material> LootFactory::piele() {
    return make_shared<Material>("piele", 0.3, 1, 6);
}

shared_ptr<Material> LootFactory::lana() {
    return make_shared<Material>("lana", 0.2, 4, 12);
}

shared_ptr<Material> LootFactory::lemn() {
    return make_shared<Material>("lemn", 0.5, 1, 4);
}

shared_ptr<Material> LootFactory::piatra() {
    return make_shared<Material>("piatra", 0.7, 1, 4);
}

shared_ptr<Material> LootFactory::clei() {
    return make_shared<Material>("clei", 0.4, 5, 15);
}