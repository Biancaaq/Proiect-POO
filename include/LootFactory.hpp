#ifndef LOOT_FACTORY_HPP
#define LOOT_FACTORY_HPP

#include <memory>
#include "Mancare.hpp"
#include "Material.hpp"

class LootFactory {
    public:
    static std::shared_ptr<Mancare> mar();
    static std::shared_ptr<Mancare> alune_padure();
    static std::shared_ptr<Mancare> fructe_padure();
    static std::shared_ptr<Mancare> suc_mere();
    static std::shared_ptr<Mancare> carne_gatita();
    static std::shared_ptr<Mancare> baton_energetic();

    static std::shared_ptr<Material> piele();
    static std::shared_ptr<Material> lana();
    static std::shared_ptr<Material> lemn();
    static std::shared_ptr<Material> piatra();
    static std::shared_ptr<Material> clei();
};

#endif
