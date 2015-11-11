#include "GameManager.h"

GameManager::GameManager()
{
	m_time = new Timer;
	m_score = new Score;
	m_save = new Save;
}

GameManager::~GameManager()
{
	if (m_time)
	{
		delete m_time;
		m_time = 0;
	}

	if (m_score)
	{
		delete m_score;
		m_score = 0;
	}

	if (m_save)
	{
		delete m_save;
		m_save = 0;
	}
}

//bool GameManager::saveGame(Model &face, Model *poo, Model &disc, Coord &camera, int &nGoal, int &nPoo) const
//{
//	fstream finOut;
//	finOut.open(SAVE, std::ios::out | std::ios::binary);
//	if (!finOut)
//	{
//		return false;
//	}
//
//	m_save->hero = face;
//	m_save->goal = disc;
//	m_save->cam = camera;
//	m_save->score = nGoal;
//	m_save->nObj = nPoo;
//	
//	m_save->enemy = new Model[nPoo];
//	for (int i = 0; i < nPoo; ++i)
//	{
//		m_save->enemy[i] = poo[i];
//	}
//	
//	finOut.write(reinterpret_cast<const char*>(&(*m_save)), sizeof(m_save));
//
//	delete m_save->enemy;
//
//	return true;
//}
