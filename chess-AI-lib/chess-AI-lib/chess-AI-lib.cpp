// This is the main DLL file.

#include "stdafx.h"

#include "chess-AI-lib.h"

namespace chessAI
{
	cChessGame::cChessGame()
	{
		mGame = new chessGame();
	}

	bool cChessGame::move(cMove move)
	{
		move_t Cmove;
		Cmove.from = (const char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(move.from)).ToPointer();
		Cmove.to = (const char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(move.to)).ToPointer();
		bool test = mGame->move(Cmove);
		return test;

	}

	cChessGame::~cChessGame()
	{
		delete mGame;
	}
}

