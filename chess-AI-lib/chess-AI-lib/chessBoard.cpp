/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   board.cpp
 * Author: Jakub
 * 
 * Created on 27. prosince 2015, 20:33
 */

#include "Stdafx.h"
#include "chessBoard.h"

namespace chessAI
{
	chessBoard::chessBoard() {
		mBoard[0][0].set(COLOUR::BLACK, STONES::ROOK);
		//mBoard = new chessPiece[64];
		for (int i = 0; i < 8; i++)
		{
			colour_t color;
			if (i == 0 || i == 7)
			{
				if (i == 0) color = COLOUR::BLACK;
				else color = COLOUR::WHITE;
				mBoard[i][0].set(color, STONES::ROOK);
				mBoard[i][1].set(color, STONES::KNIGHT);
				mBoard[i][2].set(color, STONES::BISHOP);
				mBoard[i][3].set(color, STONES::QUEEN);
				mBoard[i][4].set(color, STONES::KING);
				mBoard[i][5].set(color, STONES::BISHOP);
				mBoard[i][6].set(color, STONES::KNIGHT);
				mBoard[i][7].set(color, STONES::ROOK);
			}
			else
			{
				for (int j = 0; j < 8; j++)
				{
					if (i == 1) mBoard[i][j].set(COLOUR::BLACK, STONES::PAWN);
					else if (i == 6) mBoard[i][j].set(COLOUR::WHITE, STONES::PAWN);
				}
			}
		}
	}

	chessPiece chessBoard::moveStone(std::string from, std::string to)
	{
		chessPiece piece = mBoard[7 - (to[1] - 49)][to[0] - 65];
		if (mBoard[7 - (from[1] - 49)][from[0] - 65].getType() != STONES::EMPTY)
		{
			mBoard[7 - (to[1] - 49)][to[0] - 65] = mBoard[7 - (from[1] - 49)][from[0] - 65];
			mBoard[7 - (from[1] - 49)][from[0] - 65].set(COLOUR::NONE, STONES::EMPTY);
		}
		return piece;
	}

	void chessBoard::printPiece(string from)
	{
		cout << mBoard[7 - (from[1] - 49)][from[0] - 65];
		cout << " ";
		if (mBoard[7 - (from[1] - 49)][from[0] - 65].getColour() == COLOUR::WHITE) cout << "WHITE";
		else if (mBoard[7 - (from[1] - 49)][from[0] - 65].getColour() == COLOUR::BLACK) cout << "BLACK";
		else cout << " ";
		cout << endl;
	}

	chessPiece chessBoard::getPiece(string from)
	{
		return mBoard[7 - (from[1] - 49)][from[0] - 65];
	}
	ostream& operator<< (ostream& os, const chessBoard& Board)
	{
		os << "    A   B   C   D   E   F   G   H    \n";
		os << "  |-------------------------------|  \n";
		for (int i = 0; i < 8; i++)
		{
			os << 8 - i << " |";
			for (int j = 0; j < 8; j++)
			{
				os << " " << Board.mBoard[i][j] << " |";
			}
			os << " " << 8 - i << "\n";
			os << "  |-------------------------------|  \n";
		}
		os << "    A   B   C   D   E   F   G   H    \n\n";

		return os;
	}

	chessBoard::chessBoard(chessBoard& orig) {
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++) mBoard[i][j] = orig.mBoard[i][j];
	}

	chessBoard::~chessBoard() {
		//delete [] mBoard;
	}
}
