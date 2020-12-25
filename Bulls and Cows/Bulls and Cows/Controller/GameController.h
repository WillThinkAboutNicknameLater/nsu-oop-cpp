#pragma once

#include "../Model/GameModel.h"
#include "../Model/PlayerInterfaceModel.h"

class GameController {
public:
	GameController(GameModel* model, PlayerInterfaceModel* player);
	void start();

private:
	GameModel* _gameModel;
	PlayerInterfaceModel* _player;
};

