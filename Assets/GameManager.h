#pragma once

#include "Timer.h"
#include <fstream>
using std::fstream;

#include "Globals.h"
#include "Game.h"

#ifndef GAMEMANAGER
#define GAMEMANAGER

class GameManager
{
public:
	GameManager();
	~GameManager();

	bool saveGame(Model &face, Model* poo, Model &disc, Coord &cam, int &nGoal, int &nPoo) const;
	void loadGame();

	void setScore(int nGoal);
	Score getScore() const;

private:
	Timer*		m_time;
	Score*		m_score;
	Save*		m_save;
};

#endif