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

#define NPOO 30
#define DOTRAD 10
#define WIDTH 800
#define HIGHT 600

struct Coord
{
	Coord(int x, int y, int w)
	{
		X = x;
		Y = y;
		width = w;
	}
	Coord()
	{
		X = 0;
		Y = 0;
		width = 0;
	}
	int X;
	int Y;
	int width;
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
	void DrawDot(Coord &odject, int r, int g, int b);
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
	bool allPooIsEaten;
	int speed;
	Coord player;
	Coord poo[NPOO];
	Coord dot;

	bool pooIsEaten[NPOO];
	bool dotIsEaten;
	bool result;

	/********************************/
private:
	bool isColision(Coord &model1, Coord &model2) const;
	//bool isDone(int curPos, int endPos);
};

