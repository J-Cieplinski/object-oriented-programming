#pragma once

#include <iostream>

#include "Cargo.hpp"
#include "Item.hpp"
#include "Observer.hpp"
#include "Player.hpp"
#include "StockManagement.hpp"

const std::vector<std::string> fruitNames = {
    "apple",
    "pineapple",
    "coconut",
    "orange",
    "banana",
    "watermelon"};

const std::vector<std::string> alcoNames = {
    "whiskey",
    "rum",
    "beer",
    "ale",
    "vodka",
    "absinthe"};

const std::vector<std::string> itemNames = {
    "cutlass",
    "chest",
    "parrot",
    "old coin",
    "rusty gun",
    "pirate's flag"};

constexpr size_t marketSection{4};

enum class Response {
    done,
    lack_of_money,
    lack_of_cargo,
    lack_of_space
};

class Store : public Observer, public StockManagement {
private:
    std::shared_ptr<Time> time_{nullptr};
    size_t cargoPriceThreshold_{};
    double belowThreshMultiplier_{};
    double aboveThreshMultiplier_{};

    size_t genRand(size_t min, size_t max) const;
    void generateFruits();
    void generateAlcos();
    void generateItems();
    void makeStock();
    CargoPtr makeNewCargo(const CargoPtr& cargo, size_t amount) const;
    size_t calculateBuyPrice(const CargoPtr& cargo) const;
    void defineStoreEconomy();

public:
    Store(std::shared_ptr<Time>& time);
    ~Store() { time_->removeObserver(this); }
    Response buy(const CargoPtr& cargo, size_t amount, const std::shared_ptr<Player>& player);
    Response sell(const CargoPtr& playersCargo, size_t amount, const std::shared_ptr<Player>& player);
    CargoStock getAllCargos() const { return stock_; }

    //Override from Observer
    void nextDay() override;

    friend std::ostream& operator<<(std::ostream& out, const Store& store);
};
