#pragma once

#include <string>
#include "Shape.h"
#include "ShapeDecorator.h"

// Concrete decorator class
class ColorDecorator final : public ShapeDecorator {
public:
    ColorDecorator(std::unique_ptr<Shape>&& some_shape, const std::string& color)
        : ShapeDecorator(std::move(some_shape)), color(color) {}

    // The modified function
    std::string getName() const override {
        // Base behavior + new behavior
        return ShapeDecorator::getName() + " which is colored " + color;
    }

private:
    // The new property
    std::string color;
};