#include "IO.h"

//Screen
static SDL_Window *sdlWindow;
static SDL_Renderer *sdlRenderer;


//Init
IO::IO() {
	SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP, &sdlWindow, &sdlRenderer);
}


//Clear the screen
void IO::clearScreen() {
	SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
	SDL_RenderClear(sdlRenderer);;
}


/*
Draw a rectangle

pX1, pY1: Upper left corner of the rectangle
pX2, pY2: Lower right corner of the rectangle
pC : Rectangle color
*/
void IO::drawRectangle(int pX1, int pY1, int pX2, int pY2, enum color pC) {
	Uint8 c[4];
	//Set RGB depending on color
	switch (pC) {
	case BLACK:
		c[0] = 0;
		c[1] = 0;
		c[2] = 0;
		c[3] = 255;
		break;
	case BLUE:
		c[0] = 0;
		c[1] = 0;
		c[2] = 255;
		c[3] = 255;
		break;
	case RED :
		c[0] = 255;
		c[1] = 0;
		c[2] = 0;
		c[3] = 255;
		break;
	case GREEN :  
		c[0] = 0;
		c[1] = 128;
		c[2] = 0;
		c[3] = 255;
		break;
	case CYAN : 
		c[0] = 0;
		c[1] = 255;
		c[2] = 255;
		c[3] = 255;
		break;
	case MAGENTA : 
		c[0] = 150;
		c[1] = 0;
		c[2] = 150;
		c[3] = 150;
		break;
	case YELLOW : 
		c[0] = 255;
		c[1] = 255;
		c[2] = 0;
		c[3] = 255;
		break;
	case WHITE :
		c[0] = 255;
		c[1] = 255;
		c[2] = 255;
		c[3] = 255;
		break;
	}
	boxRGBA(sdlRenderer, pX1, pY1, pX2, pY2 - 1, c[0], c[1], c[2], c[3]);
}


//Return the screen height
int IO::getScreenHeight() {
	int h;
	SDL_GetWindowSize(sdlWindow, NULL, &h);

	return h;
}


//Update screen
void IO::updateScreen() {
	SDL_RenderPresent(sdlRenderer);
}


//Keyboard Input
int IO::pollKey() {
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type) {
		case SDL_KEYDOWN:
			return event.key.keysym.sym;
		case SDL_QUIT:
			exit(3);
		}
	}
	return -1;
}

//Keyboard Input
int IO::getKey() {
	SDL_Event event;
	while (true)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN)
			break;
		if (event.type == SDL_QUIT)
			exit(3);
	};
	return event.key.keysym.sym;
}

//Keyboard Input
int IO::isKeyDown(int pKey) {
	const Uint8* mKeytable;
	int mNumkeys;
	SDL_PumpEvents();
	mKeytable = SDL_GetKeyboardState(&mNumkeys);
	return mKeytable[pKey];
}