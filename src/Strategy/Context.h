#pragma once

#include "Strategy.h"

class Context {
public:
	void setStrategy(std::unique_ptr<Strategy>&& input_strategy) {
		curr_strategy = std::move(input_strategy);
	}

	void VeryImportantOperation() {
		curr_strategy->DoAlgorithm();
	}

private:
	std::unique_ptr<Strategy> curr_strategy;
};