#include "GameView.h"
#include "../Model/GameModel.h"

GameView::GameView(GameModel* model) : _gameModel{ model } {
	_gameModel->addObserver(this);
}

void GameView::update() {
	std::cout << "Turn " << _gameModel->getTurnNumber() << ": Your guess " << _gameModel->getEstimatedNumber() << " has " << _gameModel->getNumberOfBulls() << " bulls and " << _gameModel->getNumberOfCows() << " cows." << std::endl;
}

