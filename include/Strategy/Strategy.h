#pragma once

#include <iostream>

// Abstract base class
class Strategy {
public:
	virtual std::string DoAlgorithm() = 0;
	Strategy() = default;
	virtual ~Strategy() = default;

	Strategy(const Strategy&) = delete;
	Strategy& operator=(const Strategy&) = delete;
	Strategy(Strategy&&) = default;
	Strategy& operator=(Strategy&&) = default;
};


// Concrete strategies
class StrategyA final : public Strategy {
public:
	std::string DoAlgorithm() override {
		return "StrategyA algorithm";
	}
};

class StrategyB final : public Strategy {
public:
	std::string DoAlgorithm() override {
		return "StrategyB algorithm";
	}
};

class StrategyC final : public Strategy {
public:
	std::string DoAlgorithm() override {
		return "StrategyC algorithm";
	}
};