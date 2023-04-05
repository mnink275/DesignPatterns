#pragma once

#include <string>
#include <memory>
#include "BaseComponents.h"
#include "BaseCompositeComponents.h"

// Composite components
class MotherBoard final : public BaseCompositeComponents {
public:
	MotherBoard(const std::string& name) : BaseCompositeComponents(name) {}
};

class ComputerCase final : public BaseCompositeComponents {
public:
	ComputerCase(const std::string& name) : BaseCompositeComponents(name) {}
};

class PersonalComputer final : public BaseCompositeComponents {
public:
	PersonalComputer(const std::string& name) : BaseCompositeComponents(name) {}
};


// Unit components
class GPU final : public BaseComponents {
public:
	GPU(const std::string& name) : BaseComponents(name) {};
};

class CPU final : public BaseComponents {
public:
	CPU(const std::string& name) : BaseComponents(name) {};
};

class RAM final : public BaseComponents {
public:
	RAM(const std::string& name) : BaseComponents(name) {};
};

class SSD final : public BaseComponents {
public:
	SSD(const std::string& name) : BaseComponents(name) {};
};

class PowerSupply final : public BaseComponents {
public:
	PowerSupply(const std::string& name) : BaseComponents(name) {};
};

class Monitor final : public BaseComponents {
public:
	Monitor(const std::string& name) : BaseComponents(name) {};
};

class Mouse final : public BaseComponents {
public:
	Mouse(const std::string& name) : BaseComponents(name) {};
};

class Keyboard final : public BaseComponents {
public:
	Keyboard(const std::string& name) : BaseComponents(name) {};
};
