#pragma once

#include <list>
#include <algorithm>
#include "BaseComponents.h"

// Composite base class
class BaseCompositeComponents : public BaseComponents {
public:
	virtual ~BaseCompositeComponents() = default;

	int power() override {
		// TODO
		return 0;
	};
	int netPrice() override {
		// TODO
		return 0;
	}

	void add(std::unique_ptr<BaseComponents>&& component) override {
		components.push_back(move(component));
	}
	void remove(std::unique_ptr<BaseComponents>&& component) override {
		auto it = find(components.begin(), components.end(), component);
		components.erase(it);
	}

protected:
	BaseCompositeComponents(const std::string& name) : BaseComponents(name) {};

private:
	std::list<std::unique_ptr<BaseComponents>> components;
};