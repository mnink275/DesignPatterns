#pragma once

#include <iostream>

// Abstract base class
class Strategy {
public:
	virtual void DoAlgorithm() = 0;
	virtual ~Strategy() = default;
};


// Concrete strategies
class StrategyA : public Strategy {
public:
	void DoAlgorithm() override {
		std::cout << "StrategyA algorithm" << "\n";
	}
};

class StrategyB : public Strategy {
public:
	void DoAlgorithm() override {
		std::cout << "StrategyB algorithm" << "\n";
	}
};

class StrategyC : public Strategy {
public:
	void DoAlgorithm() override {
		std::cout << "StrategyC algorithm" << "\n";
	}
};