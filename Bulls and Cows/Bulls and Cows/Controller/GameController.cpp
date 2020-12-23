#include "GameController.h"
#include "../view/GameView.h"

GameController::GameController(GameModel* model, PlayerInterfaceModel* player) : _gameModel{ model }, _player{ player } { }

void GameController::start() {
	while (_gameModel->getGameState() != GameModel::GameState::WON) {
		std::string estimatedNumber{ _player->makeTurn() };
		_gameModel->setEstimatedNumber(estimatedNumber);
		_gameModel->calculateResult();
		_player->numberOfBulls = _gameModel->getNumberOfBulls();
		_player->numberOfCows = _gameModel->getNumberOfCows();
	}
}

