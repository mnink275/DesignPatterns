#pragma once

#include <memory>
#include "Strategy.h"

class Context final {
public:
	void setStrategy(std::unique_ptr<Strategy>&& input_strategy) {
		curr_strategy = std::move(input_strategy);
	}

	std::string VeryImportantOperation() {
		return curr_strategy->DoAlgorithm();
	}

private:
	std::unique_ptr<Strategy> curr_strategy;
};