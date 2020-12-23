#include <string>
#include <random>

#include "GameModel.h"

void GameModel::generateFictionalNumber() {
	std::random_device rd;
	size_t fictionalNumber{ rd() % 9000 + 1000 };
	_fictionalNumber = std::to_string(fictionalNumber);
}

GameModel::GameModel() {
	generateFictionalNumber();
}

void GameModel::setEstimatedNumber(const std::string& estimatedNumber) {
	_estimatedNumber = estimatedNumber;
}

void GameModel::setGameState(GameState gameState) {
	_gameState = gameState;
}

void GameModel::calculateResult() {
	_numberOfBulls = 0;
	_numberOfCows = 0;
	bool visitedFictionalDigits[]{ false, false, false, false };
	bool visitedEstimatedDigits[]{ false, false, false, false };
	for (size_t i{ 0 }; i < 4; ++i) {
		if (_estimatedNumber[i] == _fictionalNumber[i]) {
			++_numberOfBulls;
			visitedEstimatedDigits[i] = true;
			visitedFictionalDigits[i] = true;
		}
	}
	for (size_t i{ 0 }; i < 4; ++i) {
		for (size_t j{ 0 }; j < 4; ++j) {
			if (!visitedEstimatedDigits[i] && !visitedFictionalDigits[j] && _estimatedNumber[i] == _fictionalNumber[j]) {
				++_numberOfCows;
				visitedEstimatedDigits[i] = true;
				visitedFictionalDigits[j] = true;
			}
		}
	}

	++_turnNumber;
	if (getEstimatedNumber() == getFictionalNumber()) {
		setGameState(GameModel::GameState::WON);
	}
	notifyUpdate();
}

std::string GameModel::getFictionalNumber() const {
	return _fictionalNumber;
}

GameModel::GameState GameModel::getGameState() const {
	return _gameState;
}

size_t GameModel::getTurnNumber() const {
	return _turnNumber;
}

std::string GameModel::getEstimatedNumber() const {
	return _estimatedNumber;
}

size_t GameModel::getNumberOfCows() const {
	return _numberOfCows;
}

size_t GameModel::getNumberOfBulls() const {
	return _numberOfBulls;
}
