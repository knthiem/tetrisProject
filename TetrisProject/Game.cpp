#include "Game.h"
#include "windows.h"

/*
Get a random int between two ints

pA: First number
pB: Second number
*/
int Game::getRand(int pA, int pB) {
	return rand() % (pB - pA + 1) + pA;
}

//Initial game settings
Game::Game(Board *pBoard, Pieces *pPieces, IO *pIO, int pScreenHeight)
{
	mScreenHeight = pScreenHeight;

	mBoard = pBoard;

	mPieces = pPieces;

	mIO = pIO;

	initGame();
}

void Game::initGame() {
	// random numbers
	srand((unsigned int)time(NULL));

	// First piece
	mPiece = getRand(0, 6);
	mRotation = getRand(0, 3);
	mPosX = (mBoard->boardW / 2) + mPieces->getXInitialPosition(mPiece, mRotation);
	mPosY = mPieces->getYInitialPosition(mPiece, mRotation);

	// Next piece
	mNextPiece = getRand(0, 6);
	mNextRotation = getRand(0, 3);
	mNextPosX = mBoard->boardW + 5;
	mNextPosY = 5;
}

// Create a random piece
void Game::createNewPiece(){

	// The new piece
	mPiece = mNextPiece;
	mRotation = mNextRotation;
	mPosX = (mBoard->boardW / 2) + mPieces->getXInitialPosition(mPiece, mRotation);
	mPosY = mPieces->getYInitialPosition(mPiece, mRotation);

	// Random next piece
	mNextPiece = getRand(0, 6);
	mNextRotation = getRand(0, 3);
}

/*
Draw piece

Parameters:

pX : Horizontal position in blocks
pY : Vertical position in blocks
pPiece : Piece to draw
pRotation : One of the possible rotations
*/
void Game::drawPiece(int pX, int pY, int pPiece, int pRotation, bool currentPiece)
{
	color mColor;
	int tempPiece = pPiece;
	int tempPieceY = pY;

	// Obtain the position in pixel of the block that will be drawn
	int mPixelsX = mBoard->getXPosInPixels(pX);
	int mPixelsY = mBoard->getYPosInPixels(pY);

	// Travel the matrix of blocks of the piece and draw the blocks that are not empty
	for (int i = 0; i < PIECE_BLOCKS; i++) {
		for (int j = 0; j < PIECE_BLOCKS; j++) {
			// Get the type of the block and draw it with the correct color
			switch (mPieces->getBlockType(pPiece, pRotation, j, i)) {
			case 1: mColor = GREEN; break;  // For blocks that are not the pivot
			case 2: mColor = BLUE; break;   // For the pivot
			}

			if (mPieces->getBlockType(pPiece, pRotation, j, i) != 0)
				mIO->drawRectangle(mPixelsX + i * BLOCK_SIZE,
								   mPixelsY + j * BLOCK_SIZE,
								  (mPixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
								  (mPixelsY + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
								   mColor);
		}
	}

	// Create a projection of the current piece to predict where it will fall
	if (currentPiece) {
		for (int i = 0; i < PIECE_BLOCKS; i++) {
			for (int j = 0; j < PIECE_BLOCKS; j++) {
				while (mBoard->isPossibleMovement(mPosX, tempPieceY, tempPiece, mRotation)) {
					tempPieceY++;
				}
					// Get the type of the block and draw it with the correct color
					switch (mPieces->getBlockType(tempPiece, pRotation, j, i)) {
					case 1: mColor = MAGENTA; break;  // For blocks that are not the pivot
					case 2: mColor = MAGENTA; break;   // For the pivot
					}

					if (mPieces->getBlockType(tempPiece, pRotation, j, i) != 0)
						mIO->drawRectangle(mPixelsX + i * BLOCK_SIZE,
							mBoard->getYPosInPixels(tempPieceY - 1) + j * BLOCK_SIZE,
							(mPixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
							(mBoard->getYPosInPixels(tempPieceY - 1) + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
							mColor);
			}
		}
	}
}

/*
Draw the two lines that delimit the board
*/
void Game::drawBoard()
{

	// Calculate the limits of the board in pixels  
	int mX1 = BOARD_POSITION - (BLOCK_SIZE * (mBoard->boardW / 2)) - 1;
	int mX2 = BOARD_POSITION + (BLOCK_SIZE * (mBoard->boardW / 2));
	int mY = mScreenHeight - (BLOCK_SIZE * mBoard->boardH);

	// Draw rectangle that limits the board
	mIO->drawRectangle(mX1 - BOARD_LINE_WIDTH, mY, mX1, mScreenHeight - 1, BLUE);

	mIO->drawRectangle(mX2, mY, mX2 + BOARD_LINE_WIDTH, mScreenHeight - 1, BLUE);

	// Drawing blocks that are already stored in the board
	mX1 += 1;
	for (int i = 0; i < mBoard->boardW; i++)
	{
		for (int j = 0; j < mBoard->boardH; j++)
		{
			// Check if the block is filled, if so, draw it
			if (!mBoard->isFreeBlock(i, j))
				mIO->drawRectangle(mX1 + i * BLOCK_SIZE,
								   mY + j * BLOCK_SIZE,
						          (mX1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
						          (mY + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
						           RED);
		}
	}
}

/*
Draw all the objects of the scene
*/
void Game::drawScene()
{
	// Draw the delimitation
	drawBoard();

	// Draw current piece
	drawPiece(mPosX, mPosY, mPiece, mRotation, true);

	// Draw next piece
	drawPiece(mNextPosX, mNextPosY, mNextPiece, mNextRotation, false);
}
