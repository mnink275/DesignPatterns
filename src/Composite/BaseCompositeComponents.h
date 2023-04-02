#pragma once

#include <list>
#include <algorithm>
#include "BaseComponents.h"

// Composite base class
class BaseCompositeComponents : public BaseComponents {
public:
	virtual ~BaseCompositeComponents() {
		for (auto& ptr : components) {
			delete ptr;
		}
	}

	int power() override {
		// TODO
		return 0;
	};
	int netPrice() override {
		// TODO
		return 0;
	}

	void add(BaseComponents* component) override {
		components.push_back(component);
	}
	void remove(BaseComponents* component) override {
		auto it = find(components.begin(), components.end(), component);
		components.erase(it);
	}

protected:
	BaseCompositeComponents(const std::string& name) : BaseComponents(name) {};

private:
	std::list<BaseComponents*> components;
};