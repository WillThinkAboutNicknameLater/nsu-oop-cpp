#include "GameView.h"
#include "../Model/GameModel.h"

GameView::GameView(GameModel* model) : _gameModel{ model } {
	_gameModel->addObserver(this);
}

void GameView::update() {
	std::cout << "Turn " << _gameModel->getTurnNumber() << ": Your guess " << _gameModel->getEstimatedNumber() << " has " << _gameModel->getNumberOfBulls() << " bulls and " << _gameModel->getNumberOfCows() << " cows." << std::endl;
}

void GameView::printWelcomeMessage() {
	system("cls");
	std::cout << "Welcome!" << std::endl;
	std::cout << "Secret number chosen (between 1000 and 9999)." << std::endl;
	std::cout << "Start guessing!..." << std::endl;
}

void GameView::printCongratulationMessage() {
	std::cout << "Congratulations, you did it!" << std::endl;
	std::cout << "You took " << _gameModel->getTurnNumber() << " to guess the number" << std::endl;
	std::cout << "Secret number is " << _gameModel->getFictionalNumber() << "." << std::endl;
}

