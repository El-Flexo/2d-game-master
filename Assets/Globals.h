#pragma once

#ifndef GLOBALS
#define GLOBALS

#define NPOO 30
#define DOTRAD 20
#define WIDTH 799
#define HEIGHT 599
#define SCREENWIDTH 800
#define SCREENHEIGHT 600
#define WORLDWIDTH 1599
#define WORLDHEIGHT 1199
#define MAXPOOSPEED 4.0f
#define MINAPPEARDIST 30.0f
#define FACESPEED 7
#define NSCORES 10
#define TIMEBUFFLEN 20
// resolution of background grid
#define GRIDRESOLUTION 50
// camera tracking offset vertical/horizontal
// is the offset from the edge off the screen 
// to the camera tracking rectangle
#define CTRKOFFVERT 180
#define CTRKOFFHOR 240

#define SAVEFILE "save.txt"
#define SCOREFILE "score.txt"

struct Model
{
	Model() : Model(0.0f, 0.0f, 0.0f) {}

	Model(float x, float y, float w)
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

struct Score
{
	char	time[TIMEBUFFLEN];
	int		score;
};

struct Save
{
	Coord	cam;
	Model	hero;
	Model	goal;
	Model   enemy[NPOO];
	int		nObj;
	int		score;
};

#endif
