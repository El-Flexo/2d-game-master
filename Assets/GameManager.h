#pragma once

#include "Timer.h"
#include <fstream>
using std::fstream;

#ifndef GAMEMANAGER
#define GAMEMANAGER

class GameManager
{
private:
	struct Coord
	{
		int X;
		int Y;
	};
	struct Score
	{
		float time;
		int score;
	};
	struct Save
	{
		Coord camera;
		Coord hero;
		Coord enemy;
		Coord goal;
		Score score;
	};
public:
	GameManager();
	~GameManager();

	void saveGame();
	void loadGame();

	void setScore();
	Score getScore() const;

private:
	Timer*		m_time;
	Score*		m_score;
	Save*		m_save;
//	Coord		mCoord;
};


#endif