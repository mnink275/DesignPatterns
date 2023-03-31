#include <iostream>
#include "src/CompositePattern/Components.h"

int main() {
	// Whole PC
	PersonalComputer* pc = new PersonalComputer("InkPC");

	// PC components
	ComputerCase* comp_case = new ComputerCase("Corsair 4000D");
	Monitor* monitor = new Monitor("ASUS TUF Gaming");
	Keyboard* keyboard = new Keyboard("Smartbuy SBK-610");
	Mouse* mouse = new Mouse("Reddragon Impact");
	pc->add(comp_case);
	pc->add(monitor);
	pc->add(keyboard);
	pc->add(mouse);

	// Computer case components
	MotherBoard* board = new MotherBoard("ASUS PRIME B450");
	PowerSupply* supply = new PowerSupply("1000W Phanteks");
	comp_case->add(board);
	comp_case->add(supply);

	// Mother board components
	RAM* ram = new RAM("Corsair 64 GB");
	GPU* gpu = new GPU("NVIDIA RTX 4090");
	CPU* cpu = new CPU("AMD Ryzen 9 7950X");
	board->add(ram);
	board->add(cpu);
	board->add(gpu);

	std::cout << "Hello, CMake!" << "\n";
}