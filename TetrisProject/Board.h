#pragma once

#include "Pieces.h"
#include <iostream>
#include <vector>

#define BOARD_LINE_WIDTH 6			// Width of each of the two lines that delimit the board
#define BLOCK_SIZE 16				// Width and Height of each block of a piece
#define BOARD_POSITION 320			// Center position of the board from the left of the screen
#define MIN_VERTICAL_MARGIN 20		// Minimum vertical margin for the board limit 		
#define MIN_HORIZONTAL_MARGIN 20	// Minimum horizontal margin for the board limit
#define PIECE_BLOCKS 5				// Number of horizontal and vertical blocks of a matrix piece

class Board
{
public:
	Board(Pieces *pPieces, int pScreenHeight, int boardW, int boardH);

	int getXPosInPixels(int pPos);

	int getYPosInPixels(int pPos);

	int boardW, boardH;

	bool isFreeBlock(int pX, int pY);

	bool isPossibleMovement(int pX, int pY, int pPiece, int pRotation);

	void storePiece(int pX, int pY, int pPiece, int pRotation);

	void deletePossibleLines();

	bool isGameOver();

private:

	// To determine if index on board is free or filled
	enum {POS_FREE, POS_FILLED };

	std::vector<std::vector<int>> mBoard;

	Pieces *mPieces;

	int mScreenHeight;

	void initBoard(int boardW, int boardH);

	void deleteLine(int pY);

	
};

