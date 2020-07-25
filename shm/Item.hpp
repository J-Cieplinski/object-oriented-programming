#pragma once

#include "Cargo.hpp"

enum class Rarity {
    common = 1,
    rare = 2, 
    epic = 5, 
    legendary = 10
};

constexpr size_t rarityAmount{4};
constexpr Rarity possibleRarities[rarityAmount]{Rarity::common, Rarity::rare, Rarity::epic, Rarity::legendary};

class Item : public Cargo {
private:
    const Rarity rarity_{Rarity::common};

public:
    Item(const std::string& name, size_t amount, size_t basePrice, Rarity rarity);

    //override from Observer
    void nextDay() override { }

    //override from Cargo
    std::string getName() const override { return name_; }
    size_t getAmount() const override { return amount_; }
    size_t getBasePrice() const override { return basePrice_; }
    size_t getPrice() const override { return basePrice_ * static_cast<int>(rarity_); }
    Cargo& operator+=(const size_t amount) override;
    Cargo& operator-=(const size_t amount) override;
    bool operator==(const Cargo& cargo) const override;
    bool operator!=(const Cargo& cargo) const override;

    Rarity getRarity() const { return rarity_; }
};
