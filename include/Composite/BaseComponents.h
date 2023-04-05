#pragma once

#include <string>
#include <memory>
#include <list>

class BaseComponents;

// Abstract base class
class IComponents {
public:
	using kIterator = std::list<std::unique_ptr<BaseComponents>>::const_iterator;

	virtual ~IComponents() = default;

	virtual std::string getName() = 0;
	virtual std::size_t getSize() = 0;

	virtual void add(std::unique_ptr<BaseComponents>&& component) = 0;
	virtual void remove(std::unique_ptr<BaseComponents>&& component) = 0;

	virtual kIterator createIterator() = 0;
};

// Base class
class BaseComponents : public IComponents {
public:
	virtual ~BaseComponents() = default;

	std::string getName() override {
		return name;
	}
	std::size_t getSize() override {
		throw std::runtime_error("This component cannot contain other components!");
	}

	void add(std::unique_ptr<BaseComponents>&& component) override {
		throw std::runtime_error("This component cannot contain other components!");
	}
	void remove(std::unique_ptr<BaseComponents>&& component) override {
		throw std::runtime_error("This component cannot contain other components!");
	}

	kIterator createIterator() override {
		throw std::runtime_error("This component cannot contain other components!");
	}
	
protected:
	BaseComponents(const std::string& name) : name(name) {};

private:
	std::string name;
};