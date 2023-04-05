#include <gtest/gtest.h>
#include "Strategy/Context.h"
#include "Composite/Components.h"

TEST(StrategyPattern, CallingRightStrategy) {
	// Some context that can use different algorithms (strategies)
	auto context = std::make_unique<Context>();

	// Setting and using different strategies
	context->setStrategy(std::make_unique<StrategyA>());
	EXPECT_EQ(context->VeryImportantOperation(), "StrategyA algorithm");

	context->setStrategy(std::make_unique<StrategyB>());
	EXPECT_EQ(context->VeryImportantOperation(), "StrategyB algorithm");

	context->setStrategy(std::make_unique<StrategyC>());
	EXPECT_EQ(context->VeryImportantOperation(), "StrategyC algorithm");
}

TEST(CompositePattern, TraversingIntoComponents) {
	// Whole PC
	auto pc = std::make_unique<PersonalComputer>("InkPC");
	// Composite components
	auto board = std::make_unique<MotherBoard>("ASUS PRIME B450");
	auto computer_case = std::make_unique<ComputerCase>("Corsair 4000D");

	// Mother board components
	std::vector<std::string> board_components = {
		"Corsair 64 GB" , "NVIDIA RTX 4090", "AMD Ryzen 9 7950X" };
	board->add(std::make_unique<RAM>(board_components[0]));
	board->add(std::make_unique<GPU>(board_components[1]));
	board->add(std::make_unique<CPU>(board_components[2]));
	auto it = board->createIterator();
	for (int i = 0; i < board->getSize(); ++i) {
		EXPECT_EQ((*it)->getName(), board_components[i]);
		++it;
	}

	// Computer case components
	std::vector<std::string> case_components = {
		"ASUS PRIME B450" , "1000W Phanteks", "Samsung 960 EVO" };
	computer_case->add(std::move(board));
	computer_case->add(std::make_unique<PowerSupply>(case_components[1]));
	computer_case->add(std::make_unique<SSD>(case_components[2]));
	it = computer_case->createIterator();
	for (int i = 0; i < computer_case->getSize(); ++i) {
		EXPECT_EQ((*it)->getName(), case_components[i]);
		++it;
	}

	// PC components
	std::vector<std::string> pc_components = {
		"Corsair 4000D" , "ASUS TUF Gaming", "Reddragon Impact", "Smartbuy SBK-610" };
	pc->add(std::move(computer_case));
	pc->add(std::make_unique<Monitor>(pc_components[1]));
	pc->add(std::make_unique<Mouse>(pc_components[2]));
	pc->add(std::make_unique<Keyboard>(pc_components[3]));
	it = pc->createIterator();
	for (int i = 0; i < pc->getSize(); ++i) {
		EXPECT_EQ((*it)->getName(), pc_components[i]);
		++it;
	}

	// std::cout << "The PC is built successfully!" << "\n";
}

TEST(CompositePattern, ThrowsFromUnitComponent) {
	/*
	* It is impossible to add a component to a unit component, but the possibility
	* of calling such a method exists for the sameness of the interface.
	*/
	auto cpu = std::make_unique<CPU>("AMD Ryzen 9 7950X");
	EXPECT_THROW(cpu->add(std::make_unique<GPU>("NVIDIA RTX 4090")), std::runtime_error);
}