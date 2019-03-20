#include "Board.h"

Board::Board(Pieces *pPieces, int pScreenHeight, int boardWidth, int boardHeight) {
	mScreenHeight = pScreenHeight;

	mPieces = pPieces;

	boardW = boardWidth;

	boardH = boardHeight;

	mBoard.resize(boardW);
	for (int i = 0; i < boardW; ++i) {
		mBoard[i].resize(boardH);
	}

	initBoard(boardW, boardH);
}

// Initiate the board and set every positions to free
void Board::initBoard(int boardW, int boardH) {
	for (int i = 0; i < boardW; i++)
		for (int j = 0; j < boardH; j++)
			mBoard[i][j] = POS_FREE;
}

/*
Store a piece in the board

pX : Horizontal position
pY : Vertical position
pPiece : Piece to draw
pRotation : 1 of the 4 possible rotations
*/
void Board::storePiece(int pX, int pY, int pPiece, int pRotation) {
	// Store each block of the piece into the board
	for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++) {
		for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++) {
			// Check if block is not an empty block and store it in the board 
			if (mPieces->getBlockType(pPiece, pRotation, j2, i2) != 0)
				mBoard[i1][j1] = POS_FILLED;
		}
	}
}

// Check if the game is over
bool Board::isGameOver() {
	// If the first line has blocks, return true
	for (int i = 0; i < boardW; ++i) {
		if (mBoard[i][0] == POS_FILLED)
			return true;
	}

	return false;
}

/*
Delete a line of the board

pY : Vertical position of the line to delete
*/
void Board::deleteLine(int pY) {
	// Moves all the upper lines one row down
	for (int j = pY; j > 0; j--) {
		for (int i = 0; i < boardW; i++) {
			mBoard[i][j] = mBoard[i][j - 1];
		}
	}
}

// Delete all lines that should be removed
void Board::deletePossibleLines() {
	for (int j = 0; j < boardH; j++)
	{
		int i = 0;
		// Check if line in the board has a free position
		while (i < boardW)
		{
			if (mBoard[i][j] != POS_FILLED) 
				break;
			i++;
		}

		if (i == boardW) deleteLine(j);
	}
}

/*
Returns true if the block on the board is empty, false if filled

pX : Horizontal position
pY : Vertical position
*/
bool Board::isFreeBlock(int pX, int pY) {
	if (mBoard[pX][pY] == POS_FREE)
		return true;
	else
		return false;
}

/*
Returns the horizontal position in pixels of the block

pPos : Horizontal position of the block
*/
int Board::getXPosInPixels(int pPos) {
	return  ((BOARD_POSITION - (BLOCK_SIZE * (boardW / 2))) + (pPos * BLOCK_SIZE));
}

/*
Returns the vertical position in pixels of the block

pPos : Horizontal position of the block
*/
int Board::getYPosInPixels(int pPos)
{
	return ((mScreenHeight - (BLOCK_SIZE * boardH)) + (pPos * BLOCK_SIZE));
}

/*
Check if the piece can be stored at this position without any collision

pX : Horizontal position
pY : Vertical position
pPiece : Piece to draw
pRotation : One of the possible rotations
*/
bool Board::isPossibleMovement(int pX, int pY, int pPiece, int pRotation) {
	// Check collision with pieces already in the board or the board limits
	for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++) {
		for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++) {
			// Check if the piece is outside the limits of the board
			if (i1 < 0 || i1 > boardW - 1 || j1 > boardH - 1) {
				if (mPieces->getBlockType(pPiece, pRotation, j2, i2) != 0)
					return 0;
			}

			// Check if the piece has collided with a block in the board
			if (j1 >= 0) {
				if ((mPieces->getBlockType(pPiece, pRotation, j2, i2) != 0) && (!isFreeBlock(i1, j1)))
					return false;
			}
		}
	}

	// No collision
	return true;
}