#ifndef LOOT_FACTORY_HPP
#define LOOT_FACTORY_HPP

#include <memory>
#include <string>
#include <nlohmann/json.hpp>
#include "Loot.hpp"
#include "Mancare.hpp"
#include "Material.hpp"

class LootFactory {
    public:
    static std::shared_ptr<Loot> creeaza(const std::string& tip, const nlohmann::json& data);
};

#endif
