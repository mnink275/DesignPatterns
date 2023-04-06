#pragma once

#include <string>
#include <memory>
#include "Shape.h"

// Decorator base class
class ShapeDecorator : public Shape {
public:
    ShapeDecorator(std::unique_ptr<Shape>&& some_shape)
        : some_shape(std::move(some_shape)) {}

    virtual ~ShapeDecorator() = default;

    ShapeDecorator(ShapeDecorator&) = delete;
    ShapeDecorator& operator=(ShapeDecorator&) = delete;
    ShapeDecorator(ShapeDecorator&&) = default;
    ShapeDecorator& operator=(ShapeDecorator&&) = default;

    std::string getName() const override {
        return some_shape->getName();
    }

private:
    // The pointer to the decorated object
    std::unique_ptr<Shape> some_shape;
};