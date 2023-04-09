#pragma once

#include <string>

// Abstract base class
class Building {
public:
	virtual ~Building() = default;

	virtual int getSquare() = 0;
	virtual std::string getName() = 0;
};

// Concrete buildings
class Farm final : public Building {
public:
	std::string getName() override {
		return "Farm has been built!";
	}

	int getSquare() override {
		return 3;
	}
};

class Forge final : public Building {
public:
	std::string getName() override {
		return "Forge has been built!";
	}

	int getSquare() override {
		return 9;
	}
};