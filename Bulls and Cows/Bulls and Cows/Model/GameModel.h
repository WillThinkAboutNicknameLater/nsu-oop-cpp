#pragma once

#include "PlayerInterfaceModel.h"
#include "ObservableModel.h"

class GameModel : public ObservableModel {
public:
	enum class GameState {
		IN_PROGRESS,
		WON
	};

	GameModel();
	~GameModel() = default;
	void setEstimatedNumber(const std::string& estimatedNumber);
	void setGameState(GameState gameState);
	void calculateResult();
	std::string getFictionalNumber() const;
	GameState getGameState() const;
	size_t getTurnNumber() const;
	std::string getEstimatedNumber() const;
	size_t getNumberOfCows() const;
	size_t getNumberOfBulls() const;

private:
	GameState _gameState{ GameState::IN_PROGRESS };
	size_t _turnNumber{ 0 };
	std::string _fictionalNumber{ 0 };
	std::string _estimatedNumber{ 0 };
	size_t _numberOfCows{ 0 };
	size_t _numberOfBulls{ 0 };
	
	void generateFictionalNumber();
};

