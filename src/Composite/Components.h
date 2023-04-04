#pragma once

#include <string>
#include "BaseComponents.h"
#include "BaseCompositeComponents.h"

// Composite components
class MotherBoard : public BaseCompositeComponents {
public:
	MotherBoard(const std::string& name) : BaseCompositeComponents(name) {}
};

class ComputerCase : public BaseCompositeComponents {
public:
	ComputerCase(const std::string& name) : BaseCompositeComponents(name) {}
};

class PersonalComputer : public BaseCompositeComponents {
public:
	PersonalComputer(const std::string& name) : BaseCompositeComponents(name) {}
};


// Unit components
class GPU : public BaseComponents {
public:
	GPU(const std::string& name) : BaseComponents(name) {};
};

class CPU : public BaseComponents {
public:
	CPU(const std::string& name) : BaseComponents(name) {};
};

class RAM : public BaseComponents {
public:
	RAM(const std::string& name) : BaseComponents(name) {};
};

class SSD : public BaseComponents {
public:
	SSD(const std::string& name) : BaseComponents(name) {};
};

class PowerSupply : public BaseComponents {
public:
	PowerSupply(const std::string& name) : BaseComponents(name) {};
};

class Monitor : public BaseComponents {
public:
	Monitor(const std::string& name) : BaseComponents(name) {};
};

class Mouse: public BaseComponents {
public:
	Mouse(const std::string& name) : BaseComponents(name) {};
};

class Keyboard : public BaseComponents {
public:
	Keyboard(const std::string& name) : BaseComponents(name) {};
};
