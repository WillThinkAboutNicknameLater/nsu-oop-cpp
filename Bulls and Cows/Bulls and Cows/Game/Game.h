#pragma once

#include "../Model/GameModel.h"

class Game {
public:
	enum class GameMode {
		HUMAN,
		BOT
	};

	void run();

private:
	GameMode _gameMode;
	void setGameMode();
};