#pragma once

#include <list>
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

	void add(BaseComponents* eq) override {
		equipment.push_back(eq);
	}
	void remove(BaseComponents* eq) override {
		auto it = find(equipment.begin(), equipment.end(), eq);
		equipment.erase(it);
	}

protected:
	BaseCompositeComponents(const std::string& name) : BaseComponents(name) {};

private:
	std::list<BaseComponents*> equipment;
};