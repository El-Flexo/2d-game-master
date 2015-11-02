/****************************************************************************************** 
 *	Chili DirectX Framework Version 11.12.17											  *	
 *	Game.h																				  *
 *	Copyright 2011 PlanetChili.net														  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "D3DGraphics.h"
#include "Keyboard.h"
#include <cstdlib>
#include <ctime>
#include <utility>

#define NPOO 30
#define DOTRAD 10
#define WIDTH 799
#define HIGHT 599

struct Model
{
	Model(int x, int y, int w)
	{
		X = x;
		Y = y;
		width = w;
	}
	Model()
	{
		X = 0;
		Y = 0;
		width = 0;
	}
	float X;
	float Y;
	int width;
	float xVelocity;
	float yVelocity;
};

class Game
{
public:
	Game( HWND hWnd,const KeyboardServer& kServer );
	void Go();
	void mazeGenerator();

private:
	void ComposeFrame();
	/********************************/
	/*  User Functions              */
	void DrawPoo(int x, int y);
	void DrawDot(Model &odject, int r, int g, int b);
	void DrawPlayer(int x, int y);
	void DrawGameOver(int x, int y);
	void UpdateFace();
	void UpdatePoo();
	void UpdateDot();
	void UpdateScene();

	/********************************/
private:
	D3DGraphics gfx;
	KeyboardClient kbd;
	/********************************/
	/*  User Variables              */
	int nPoo;
	int speed;
	Model player;
	Model poo[NPOO];
	Model dot;

	bool dotIsEaten;
	bool gameIsOver;

	/********************************/
private:
	bool isCollision(Model &model1, Model &model2) const;
	//bool isDone(int curPos, int endPos);
};

