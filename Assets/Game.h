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
#include "Mouse.h"
#include "Sound.h"
#include <cstdlib>
#include <ctime>
#include <utility>

#include "GameManager.h"

#define NPOO 30
#define DOTRAD 20
#define WIDTH 799
#define HEIGHT 599
#define MAXPOOSPEED 4.0f
#define MINAPPEARDIST 30.0f
#define FACESPEED 7
#define WORLDHEIGHT 1199
#define WORLDWIDTH 1599
 // resolution of background grid
#define GRIDRESOLUTION 50
 // camera tracking offset vertical/horizontal
 // is the offset from the edge off the screen 
 // to the camera tracking rectangle
#define CTRKOFFVERT 180
#define CTRKOFFHOR 240

struct Model
{
	Model() : Model(0, 0, 0) {}

	Model(int x, int y, int w)
	{
		width = w;
		X = x;
		Y = y;
		cX = 0.0f;
		cY = 0.0f;
		xVelocity = 0.0f;
		yVelocity = 0.0f;
	}

	float X;
	float Y;
	float cX;
	float cY;
	int width;
	float xVelocity;
	float yVelocity;
};

struct Coord
{
	int X;
	int Y;
};

class Game
{
public:
	Game( HWND hWnd, const KeyboardServer& kServer, const MouseServer& mServer);
	void Go();
	void mazeGenerator();

private:
	void ComposeFrame();
	/********************************/
	/*  User Functions              */
	void DrawPlayerClipped(int x, int y);
	void DrawPooClipped(int x, int y);
	void DrawPooUnclipped(int x, int y);
	void DrawDot(Model &odject, int r, int g, int b);
	void DrawGameOver(int x, int y);
	void UpdateFace();
	void UpdatePoo();
	void UpdateCamera();
	void UpdateScene();
	void RandomizePooVelocity(int index);
	void RandomizePooPosition(int index);
	void ResetGame();
	void ResetGoal();
	bool isCollision(Model &model1, Model &model2) const;
	bool isCollisionRound(Model &model1, Model &model2) const;
	// unlike drawface and drawpoo, drawbackground works
	// in world space instead of screen space, so it needs
	// the camera coordinates
	void DrawBackgroundClipped(const Coord &camera);

	/********************************/
private:
	D3DGraphics			gfx;
	KeyboardClient		kbd;
	MouseClient			mouse;
	DSound				audio;
	/********************************/
	/*  User Variables              */
	int			nPoo;
	int			nGoal;
	Model		player;
	Model		poo[NPOO];
	Model		dot;
	Coord		camera;

	bool		gameIsOver;

	Sound		fart;
	Sound		ting;
	/********************************/
};

