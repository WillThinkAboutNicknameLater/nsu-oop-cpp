#pragma once

#include "PlayerInterfaceModel.h"

class HumanPlayerModel : public PlayerInterfaceModel {
public:
	HumanPlayerModel() = default;
	~HumanPlayerModel() = default;
	std::string makeTurn() override;
};

