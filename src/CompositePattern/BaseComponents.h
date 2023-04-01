#pragma once

#include <string>

class BaseComponents;

// Abstract base class
class IComponents {
public:
	virtual ~IComponents() = default;

	virtual std::string getName() = 0;
	virtual int power() = 0;
	virtual int netPrice() = 0;

	virtual void add(BaseComponents* component) = 0;
	virtual void remove(BaseComponents* component) = 0;
};

// Base class
class BaseComponents : public IComponents {
public:
	virtual ~BaseComponents() = default;

	std::string getName() override {
		return name;
	}

	int power() override {
		/*
		int pwr = getPower();
		return pwr;
		*/
		return 0;
	};
	int netPrice() override {
		/*
		int price = getNetPrice();
		return price;
		*/
		return 0;
	}

	virtual void add(BaseComponents* component) {
		throw std::runtime_error("This equipment cannot contain other equipments!");
	}
	virtual void remove(BaseComponents* component) {
		throw std::runtime_error("This equipment cannot contain other equipments!");
	}
protected:
	BaseComponents(const std::string& name) : name(name) {};

private:
	std::string name;
};

//// Base class
//class BaseComponents {
//public:
//	virtual ~BaseComponents() = default;
//
//	virtual std::string getName() {
//		return name;
//	}
//
//	virtual int power() {
//		/*
//		int pwr = getPower();
//		return pwr;
//		*/
//		return 0;
//	};
//	virtual int netPrice() {
//		/*
//		int price = getNetPrice();
//		return price;
//		*/
//		return 0;
//	}
//
//	virtual void add(BaseComponents* component) {
//		throw std::runtime_error("This equipment cannot contain other equipments!");
//	}
//	virtual void remove(BaseComponents* component) {
//		throw std::runtime_error("This equipment cannot contain other equipments!");
//	}
//protected:
//	BaseComponents(const std::string& name) : name(name) {};
//
//private:
//	std::string name;
//};