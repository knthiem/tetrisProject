#pragma once   
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>


enum color { BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE};

class IO
{
public:
	IO();

	void drawRectangle(int pX1, int pY1, int pX2, int pY2, enum color pC);

	void clearScreen();

	int getScreenHeight();

	int pollKey();

	int getKey();

	int isKeyDown(int pKey);

	void updateScreen();
};

