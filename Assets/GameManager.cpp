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