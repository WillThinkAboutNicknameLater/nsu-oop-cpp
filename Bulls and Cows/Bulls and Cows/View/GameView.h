#pragma once

#include "../Model/GameModel.h"
#include "../Model/ObserverModel.h"
#include "../Model/GameModel.h"

class GameView : public ObserverModel {
public:
	GameView(GameModel* model);
	virtual void update();

private:
	GameModel* _gameModel;
};

