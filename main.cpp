#include <iostream>
#include "src/CompositePattern/Components.h"

int main() {
	// Whole PC
	auto pc = new PersonalComputer("InkPC");

	// PC components
	auto comp_case = new ComputerCase("Corsair 4000D");
	auto monitor = new Monitor("ASUS TUF Gaming");
	auto keyboard = new Keyboard("Smartbuy SBK-610");
	auto mouse = new Mouse("Reddragon Impact");
	pc->add(comp_case);
	pc->add(monitor);
	pc->add(keyboard);
	pc->add(mouse);

	// Computer case components
	auto board = new MotherBoard("ASUS PRIME B450");
	auto supply = new PowerSupply("1000W Phanteks");
	comp_case->add(board);
	comp_case->add(supply);

	// Mother board components
	auto ram = new RAM("Corsair 64 GB");
	auto gpu = new GPU("NVIDIA RTX 4090");
	auto cpu = new CPU("AMD Ryzen 9 7950X");
	board->add(ram);
	board->add(cpu);
	board->add(gpu);

	/*
	* It is impossible to add a component to a unit component, but the possibility
	* of calling such a method exists for the sameness of the interface.
	*/
	try {
		cpu->add(gpu);
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << "\n";
	}

	std::cout << "The PC is built successfully!" << "\n";

	/*
	* Deleting the root of a "tree" --> ñauses chain deletion of all components 
	* (with destructor of BaseCompositeComponents class is correct.
	*/
	delete pc;
}