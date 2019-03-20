#pragma once

#include "Board.h"
#include "Pieces.h"
#include "IO.h"
#include <time.h>
#include <stdlib.h>


class Game
{
public:
	Game(Board *pBoard, Pieces *pPieces, IO *pIO, int pScreenHeight);

	void drawScene();

	void createNewPiece();

	// Position of the piece
	int mPosX, mPosY;

	// Type and rotation of the piece
	int mPiece, mRotation;

private:

	int mScreenHeight;

	// Position of the next piece
	int mNextPosX, mNextPosY;

	// Type and rotation of the next piece
	int mNextPiece, mNextRotation;

	Board *mBoard;

	Pieces *mPieces;

	IO *mIO;
	
	int getRand(int pA, int pB);

	void initGame();

	void drawPiece(int pX, int pY, int pPiece, int pRotation, bool currentPiece);

	void drawBoard();
};

