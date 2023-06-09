#pragma once

#include <list>
#include <memory>
#include <algorithm>
#include "BaseComponents.h"

// Composite base class
class BaseCompositeComponents : public BaseComponents {
public:
	virtual ~BaseCompositeComponents() = default;

	BaseCompositeComponents(const  BaseCompositeComponents&) = delete;
	BaseCompositeComponents& operator=(const  BaseCompositeComponents&) = delete;
	BaseCompositeComponents(BaseCompositeComponents&&) = default;
	BaseCompositeComponents& operator=(BaseCompositeComponents&&) = default;

	std::size_t getSize() const override {
		return components.size();
	}

	void add(std::unique_ptr<BaseComponents>&& component) override {
		components.push_back(move(component));
	}
	void remove(std::unique_ptr<BaseComponents>&& component) override {
		auto it = find(components.begin(), components.end(), component);
		components.erase(it);
	}

	kIterator createIterator() const override {
		return components.cbegin();
	}
protected:
	BaseCompositeComponents(const std::string& name) : BaseComponents(name) {};

private:
	std::list<std::unique_ptr<BaseComponents>> components;
};