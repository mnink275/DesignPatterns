#pragma once

#include <string>

template <typename SomeShape>
class ColoredShape final : public SomeShape {
public:
    ColoredShape(const std::string& color) : color(color) {}

    // The modified function
    std::string getName() const override {
        // Base behavior + new behavior
        return SomeShape::getName() + " which is colored " + color;
    }

private:
    // The new property
    std::string color;
};