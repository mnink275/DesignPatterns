#pragma once

#include <memory>
#include "Buildings.h"

// Buildings types
enum BuildingsType {
	FARM, FORGE
};

// ABC Factory
class Factory {
public:
	virtual ~Factory() = default;
	virtual std::unique_ptr<Building> makeBuilding(BuildingsType build_type) = 0;
};

// Concrete Factory (buildings factory)
class MakeBuilding final : public Factory {
public:
	std::unique_ptr<Building> makeBuilding(BuildingsType build_type) override {
		switch (build_type) {
			case FARM: return std::make_unique<Farm>();
			case FORGE: return std::make_unique<Forge>();
		}
	}
};