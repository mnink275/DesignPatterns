#pragma once

#include <string>

// Abstract base class
struct Shape {
	Shape() = default;
	virtual ~Shape() = default;

	Shape(Shape&) = delete;
	Shape& operator=(Shape&) = delete;
	Shape(Shape&&) = default;
	Shape& operator=(Shape&&) = default;

	virtual std::string getName() const = 0;
};