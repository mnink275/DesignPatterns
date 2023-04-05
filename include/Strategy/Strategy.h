#pragma once

#include <iostream>

// Abstract base class
class Strategy {
public:
	virtual std::string DoAlgorithm() = 0;
	virtual ~Strategy() = default;
};


// Concrete strategies
class StrategyA : public Strategy {
public:
	std::string DoAlgorithm() override {
		return "StrategyA algorithm";
	}
};

class StrategyB : public Strategy {
public:
	std::string DoAlgorithm() override {
		return "StrategyB algorithm";
	}
};

class StrategyC : public Strategy {
public:
	std::string DoAlgorithm() override {
		return "StrategyC algorithm";
	}
};