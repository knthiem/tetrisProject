#include <iostream>
#include <string>
#include "Game.h"
#include "IO.h"
#include "Board.h"
#include "Pieces.h"
#include <SDL.h>
#include <Windows.h>
using namespace std;

// Verify user input
int checkInput(int min, int max) {
	string userInput;
	int validatedInput;
	bool isValid = false;

	do {
		cout << "Enter number between " << min << " and " << max << " : ";
		cin >> userInput;

		for (int i = 0; i < userInput.size(); i++) {
			if (!isdigit(userInput[i])) {
				cout << "Please enter a valid number!" << endl;
				break;
			}
			else {
				isValid = true;
			}
		}

		if (isValid) {
			validatedInput = std::stoi(userInput);
			if (validatedInput < min || validatedInput > max) {
				isValid = false;
				cout << "Number should be between " << min << " and " << max << endl;
			}
		}
	} while (isValid != true);

	return validatedInput;
}

int main(int argc, char * argv[])
{
	int boardW, boardH, waitTime;
	
	cout << "Set game settings" << endl;

	cout << "Board width" << endl;
	boardW = checkInput(10, 30);

	cout << "Board height" << endl;
	boardH = checkInput(20, 50);

	cout << "Speed" << endl;
	waitTime = 700 / checkInput(1, 10);


	//Initialize classes
	IO mIO;
	int mScreenHeight = mIO.getScreenHeight();

	Pieces mPieces;

	Board mBoard(&mPieces, mScreenHeight, boardW, boardH);

	Game mGame(&mBoard, &mPieces, &mIO, mScreenHeight);

	unsigned long mTime1 = SDL_GetTicks();

	// Game loop. Exit with ESC
	while (!mIO.isKeyDown(SDLK_ESCAPE)) {
		// Draw screen
		mIO.clearScreen();
		mGame.drawScene();
		mIO.updateScreen();

		// Input

		int mKey = mIO.pollKey();

		switch (mKey) {
		// Move right
		case (SDLK_RIGHT): {
			if (mBoard.isPossibleMovement(mGame.mPosX + 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
				mGame.mPosX++;
			break;
		}
		// Move left
		case (SDLK_LEFT): {
			if (mBoard.isPossibleMovement(mGame.mPosX - 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
				mGame.mPosX--;
			break;
		}
		// Move down
		case (SDLK_DOWN): {
			if (mBoard.isPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
				mGame.mPosY++;
			break;
		}
		
		// Make piece fall to the ground
		case (SDLK_c): {
			// Check collision
			while (mBoard.isPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation)) { 
				mGame.mPosY++; 
			}

			mBoard.storePiece(mGame.mPosX, mGame.mPosY - 1, mGame.mPiece, mGame.mRotation);

			mBoard.deletePossibleLines();

			if (mBoard.isGameOver())
			{
				mIO.getKey();
				exit(0);
			}

			mGame.createNewPiece();

			break;
		}

		// Rotate the piece if possible
		case (SDLK_z): {
			if (mBoard.isPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 1) % 4))
				mGame.mRotation = (mGame.mRotation + 1) % 4;

			break;
		}
		}

		// Vertical movement

		unsigned long mTime2 = SDL_GetTicks();

		// The piece will fall down one block when wait time has passed
		if ((mTime2 - mTime1) > waitTime) {
			if (mBoard.isPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation)) {
				mGame.mPosY++;
			}
			else {
				mBoard.storePiece(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation);

				mBoard.deletePossibleLines();

				if (mBoard.isGameOver()) {
					mIO.getKey();
					exit(0);
				}

				mGame.createNewPiece();
			}

			mTime1 = SDL_GetTicks();
		}
	}

	return 0;
}