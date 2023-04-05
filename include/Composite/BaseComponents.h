#pragma once

#include <string>
#include <memory>
#include <list>

class BaseComponents;

// Abstract base class
class IComponents {
public:
	using kIterator = std::list<std::unique_ptr<BaseComponents>>::const_iterator;
	IComponents() = default;
	virtual ~IComponents() = default;

	IComponents(const IComponents&) = delete;
	IComponents& operator=(const Strategy&) = delete;
	IComponents(IComponents&&) = default;
	IComponents& operator=(IComponents&&) = default;

	virtual std::string getName() const = 0;
	virtual std::size_t getSize() const = 0;

	virtual void add(std::unique_ptr<BaseComponents>&& component) = 0;
	virtual void remove(std::unique_ptr<BaseComponents>&& component) = 0;

	virtual kIterator createIterator() const = 0;
};

// Base class
class BaseComponents : public IComponents {
public:
	virtual ~BaseComponents() = default;

	BaseComponents(const BaseComponents&) = delete;
	BaseComponents& operator=(const BaseComponents&) = delete;
	BaseComponents(BaseComponents&&) = default;
	BaseComponents& operator=(BaseComponents&&) = default;

	std::string getName() const override {
		return name;
	}
	std::size_t getSize() const override {
		throw std::runtime_error("This component cannot contain other components!");
	}

	void add(std::unique_ptr<BaseComponents>&& component) override {
		throw std::runtime_error("This component cannot contain other components!");
	}
	void remove(std::unique_ptr<BaseComponents>&& component) override {
		throw std::runtime_error("This component cannot contain other components!");
	}

	kIterator createIterator() const override {
		throw std::runtime_error("This component cannot contain other components!");
	}
	
protected:
	BaseComponents(const std::string& name) : name(name) {};

private:
	std::string name;
};