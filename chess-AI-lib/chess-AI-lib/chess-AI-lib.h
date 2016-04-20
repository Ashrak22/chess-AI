// chess-AI.h

#pragma once
#include "chessGame.h"

using namespace System;
using namespace chessAI;

namespace chessAI {

	public ref struct cMove
	{
		String^ from;
		String^ to;
	};

	public ref class cChessGame
	{
		// TODO: Add your methods for this class here.
	private:
		chessGame *mGame;
	public:
		cChessGame();
		bool move(cMove^ move);

		~cChessGame();

	};



	public ref class cChessBoard
	{

	};
}
