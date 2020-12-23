#pragma once

#include <iostream>

class PlayerInterfaceModel {
public:
	PlayerInterfaceModel() = default;
	~PlayerInterfaceModel() = default;
	virtual std::string makeTurn() = 0;

	size_t numberOfBulls;
	size_t numberOfCows;
};

