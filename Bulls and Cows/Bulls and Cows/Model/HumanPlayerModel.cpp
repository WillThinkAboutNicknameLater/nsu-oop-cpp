#include <iostream>
#include <string>

#include "HumanPlayerModel.h"

bool IsValidData(const std::string& data) {
	if (data.length() != 4) {
		return false;
	}

	for (auto character : data) {
		if (character < '0' || character > '9') {
			return false;
		}
	}

	return data[0] != '0';

}

std::string HumanPlayerModel::makeTurn() {
	std::string estimatedNumber{ 0 };
	std::cin >> estimatedNumber;

	while (!IsValidData(estimatedNumber)) {
		std::cout << "Invalid input!" << std::endl;
		std::cin >> estimatedNumber;
	}

	return estimatedNumber;
}