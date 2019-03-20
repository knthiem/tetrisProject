#include "Pieces.h"

// Define pieces

// 7 different type of pieces, 4 possible rotation, Stored in a 5x5 matrices
char pieces[7][4][5][5] = {
	// 2 means pivot block, 1 means regular block

	// Square
{
   {
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 2, 1, 0},
	{0, 0, 1, 1, 0},
	{0, 0, 0, 0, 0}
	},
   {
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 2, 1, 0},
	{0, 0, 1, 1, 0},
	{0, 0, 0, 0, 0}
	},
   {
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 2, 1, 0},
	{0, 0, 1, 1, 0},
	{0, 0, 0, 0, 0}
	},
   {
	{0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0},
	{0, 0, 2, 1, 0},
	{0, 0, 1, 1, 0},
	{0, 0, 0, 0, 0}
	}
   },

	// I
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 1, 2, 1, 1},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 2, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{1, 1, 2, 1, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 2, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		}
	   }
	  ,
	// L
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 2, 0, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 1, 2, 1, 0},
		{0, 1, 0, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 1, 1, 0, 0},
		{0, 0, 2, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0},
		{0, 1, 2, 1, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		}
	   },
	// L mirrored
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 2, 0, 0},
		{0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0},
		{0, 1, 2, 1, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 2, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 1, 2, 1, 0},
		{0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0}
		}
	   },
	// N
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 1, 2, 0, 0},
		{0, 0, 1, 1, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 1, 2, 0, 0},
		{0, 1, 0, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 1, 1, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		}
	   },
	// N mirrored
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0},
		{0, 1, 2, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 1, 0},
		{0, 1, 2, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		}
	   },
	// T
	  {
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 2, 1, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 1, 2, 1, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 1, 2, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0}
		},
	   {
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 1, 2, 1, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		}
	   }
};

// Pieces need to be placed correctly on top of the screen when created. This array stores the displacement
// 7 type of pieces, 4 rotation, 2 position
int piecesInitialPosition[7][4][2] = {
	// Square
	  {
		{-2, -3},
		{-2, -3},
		{-2, -3},
		{-2, -3}
	   },
	// I
	  {
		{-2, -2},
		{-2, -3},
		{-2, -2},
		{-2, -3}
	   },
	// L 
	  {
		{-2, -3},
		{-2, -3},
		{-2, -3},
		{-2, -2}
	   },
	// L mirrored
	  {
		{-2, -3},
		{-2, -2},
		{-2, -3},
		{-2, -3}
	   },
	// N
	  {
		{-2, -3},
		{-2, -3},
		{-2, -3},
		{-2, -2}
	   },
	// N mirrored
	  {
		{-2, -3},
		{-2, -3},
		{-2, -3},
		{-2, -2}
	   },
	// T
	  {
		{-2, -3},
		{-2, -3},
		{-2, -3},
		{-2, -2}
	   },
};

/* 

Return the type of a block

pPiece : Piece to draw
pRotation : One of the rotation
pX : Horizontal position
pY : Vertical position

*/

int Pieces::getBlockType(int pPiece, int pRotation, int pX, int pY)
{
	return pieces[pPiece][pRotation][pX][pY];
}

/*

Return the horizontal displacement of the piece neededto create it in the correct position

pPiece : Piece to draw
pRotation : One of the possible rotation

*/
int Pieces::getXInitialPosition(int pPiece, int pRotation)
{
	return piecesInitialPosition[pPiece][pRotation][0];
}

/*

Return the vertical displacement of the piece neededto create it in the correct position

pPiece : Piece to draw
pRotation : One of the possible rotation

*/
int Pieces::getYInitialPosition(int pPiece, int pRotation)
{
	return piecesInitialPosition[pPiece][pRotation][1];
}
