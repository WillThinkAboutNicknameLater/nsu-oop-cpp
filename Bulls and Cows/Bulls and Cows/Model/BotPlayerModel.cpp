#include <string>

#include "BotPlayerModel.h"

BotPlayerModel::BotPlayerModel() {
	for (size_t idx{ 0 }; idx < AMOUNT_OF_NUMBERS; ++idx) {
		_suitableNumbers[idx] = true;
	}
}

bool AnalyzeNumber(std::string possibleNumber, std::string suitableNumber, size_t requiredNumberOfBulls, size_t requiredNumberOfCows) {
	size_t numberOfBulls{ 0 };
	for (size_t idx{ 0 }; idx < 4; ++idx) {
		if (possibleNumber[idx] == suitableNumber[idx]) {
			++numberOfBulls;
		}
	}

	if (numberOfBulls != requiredNumberOfBulls) {
		return false;
	}

	size_t numberOfCows{ 0 };
	for (size_t idx{ 0 }; idx < 4; ++idx) {
		if (possibleNumber[idx] != suitableNumber[idx] && possibleNumber.find(suitableNumber[idx]) != std::string::npos) {
			++numberOfCows;
		}
	}

	if (numberOfCows < requiredNumberOfCows) {
		return false;
	}

	return true;
}



std::string BotPlayerModel::makeTurn() {
	if (!_estimatedNumber.empty()) {
		for (size_t idx{ 0 }; idx < AMOUNT_OF_NUMBERS; ++idx) {
			if (_suitableNumbers[idx] && !AnalyzeNumber(std::to_string(idx + 1000), _estimatedNumber, numberOfBulls, numberOfCows)) {
				_suitableNumbers[idx] = false;
			}
		}
	}

	for (size_t idx{ 0 }; idx < AMOUNT_OF_NUMBERS; ++idx) {
		if (_suitableNumbers[idx]) {
			_estimatedNumber = std::to_string(idx + 1000);
			break;
		}
	}

	return _estimatedNumber;
}




