#include <iostream>
#include "src/Composite/Components.h"
#include "src/Strategy/Context.h"

int main() {
	// Composite pattern
	// Whole PC
	auto pc = std::make_unique<PersonalComputer>("InkPC");

	// Composite components
	auto board = std::make_unique<MotherBoard>("ASUS PRIME B450");
	auto computer_case = std::make_unique<ComputerCase>("Corsair 4000D");
		
	// Mother board components
	board->add(std::make_unique<RAM>("Corsair 64 GB"));
	board->add(std::make_unique<GPU>("NVIDIA RTX 4090"));
	board->add(std::make_unique<CPU>("AMD Ryzen 9 7950X"));
	
	// Computer case components
	computer_case->add(std::move(board));
	computer_case->add(std::make_unique<PowerSupply>("1000W Phanteks"));
	computer_case->add(std::make_unique<SSD>("Samsung 960 EVO"));

	// PC components
	pc->add(std::move(computer_case));
	pc->add(std::make_unique<Monitor>("ASUS TUF Gaming"));
	pc->add(std::make_unique<Mouse>("Reddragon Impact"));
	pc->add(std::make_unique<Keyboard>("Smartbuy SBK-610"));

	std::cout << "The PC is built successfully!" << "\n";

	/*
	* It is impossible to add a component to a unit component, but the possibility
	* of calling such a method exists for the sameness of the interface.
	*/
	auto cpu = std::make_unique<CPU>("AMD Ryzen 9 7950X");
	try {
		cpu->add(std::make_unique<GPU>("NVIDIA RTX 4090"));
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << "\n";
	}

	// Strategy pattern
	auto context = std::make_unique<Context>();
	
	context->setStrategy(std::make_unique<StrategyA>());
	context->VeryImportantOperation();

	context->setStrategy(std::make_unique<StrategyB>());
	context->VeryImportantOperation();

	context->setStrategy(std::make_unique<StrategyC>());
	context->VeryImportantOperation();
}