#pragma once

#include <vector>

#include "PlayerInterfaceModel.h"

class BotPlayerModel : public PlayerInterfaceModel {
public:
	BotPlayerModel();
	~BotPlayerModel() = default;
	std::string makeTurn() override;

protected:
	static const size_t AMOUNT_OF_NUMBERS{ 9000 };
	std::string _estimatedNumber;
	bool _suitableNumbers[AMOUNT_OF_NUMBERS];
};

