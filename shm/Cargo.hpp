#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Observer.hpp"

class Cargo : public Observer {
protected:
    std::string name_;
    size_t amount_;
    size_t basePrice_;

public:
    Cargo(const std::string& name, size_t amount, size_t basePrice);

    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getBasePrice() const = 0;
    virtual size_t getPrice() const = 0;

    virtual Cargo& operator+=(const size_t amount) = 0;
    virtual Cargo& operator-=(const size_t amount) = 0;
    virtual bool operator==(const Cargo& cargo) const = 0;
    virtual bool operator!=(const Cargo& cargo) const = 0;
};

using CargoPtr = std::shared_ptr<Cargo>;
using CargoPtrsVector = std::vector<std::shared_ptr<Cargo>>;
