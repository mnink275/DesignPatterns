#pragma once

#include <string>
#include "BaseComponents.h"
#include "BaseCompositeComponents.h"

// Composite components
class MotherBoard : public BaseCompositeComponents {
public:
	MotherBoard(const std::string& name) : BaseCompositeComponents(name) {}
	virtual ~MotherBoard() = default;
};

class ComputerCase : public BaseCompositeComponents {
public:
	ComputerCase(const std::string& name) : BaseCompositeComponents(name) {}
	virtual ~ComputerCase() = default;
};

class PersonalComputer : public BaseCompositeComponents {
public:
	PersonalComputer(const std::string& name) : BaseCompositeComponents(name) {}
	virtual ~PersonalComputer() = default;
};


// Unit components
class GPU : public BaseComponents {
public:
	GPU(const std::string& name) : BaseComponents(name) {};
	virtual ~GPU() = default;
};

class CPU : public BaseComponents {
public:
	CPU(const std::string& name) : BaseComponents(name) {};
	virtual ~CPU() = default;
};

class RAM : public BaseComponents {
public:
	RAM(const std::string& name) : BaseComponents(name) {};
	virtual ~RAM() = default;
};

class SDD : public BaseComponents {
public:
	SDD(const std::string& name) : BaseComponents(name) {};
	virtual ~SDD() = default;
};

class PowerSupply : public BaseComponents {
public:
	PowerSupply(const std::string& name) : BaseComponents(name) {};
	virtual ~PowerSupply() = default;
};

class Monitor : public BaseComponents {
public:
	Monitor(const std::string& name) : BaseComponents(name) {};
	virtual ~Monitor() = default;
};

class Mouse: public BaseComponents {
public:
	Mouse(const std::string& name) : BaseComponents(name) {};
	virtual ~Mouse() = default;
};

class Keyboard : public BaseComponents {
public:
	Keyboard(const std::string& name) : BaseComponents(name) {};
	virtual ~Keyboard() = default;
};
