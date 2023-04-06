#pragma once

#include <string>
#include "../Dynamic Decorator/Shape.h"

// Concrete shape class
class BaseCircle : public Shape {
public:
    BaseCircle() = default;
    virtual ~BaseCircle() = default;

    BaseCircle(BaseCircle&) = default;
    BaseCircle& operator=(BaseCircle&) = default;
    BaseCircle(BaseCircle&&) = default;
    BaseCircle& operator=(BaseCircle&&) = default;

    // Some functionality
    void resize(int factor) {
        radius *= factor;
    }

    // The method to be modified
    std::string getName() const override {
        return std::string("A circle of radius ") + std::to_string(radius);
    }

private:
    int radius{ 10 };
};