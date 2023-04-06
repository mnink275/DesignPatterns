#pragma once

#include <string>
#include "Shape.h"

// Concrete shape class
class Circle final : public Shape {
public:
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