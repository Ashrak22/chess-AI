/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   chessGame.h
 * Author: Jakub
 *
 * Created on 16. ledna 2016, 18:58
 */

#ifndef CHESSGAME_H
#define CHESSGAME_H
#include "chessBoard.h"
#include <vector>

namespace chessAI
{
	struct move
	{
		string from;
		string to;
	} typedef move_t;

	class chessGame {
	public:
		chessGame();
		chessGame(const chessGame& orig);
		bool move(move_t tryMove);
		
		chessBoard showBoard();
		friend ostream& operator<< (ostream& os, chessGame& game);
		virtual ~chessGame();
	private:
		bool validatePawn(move_t tryMove);
		bool validateRook(move_t tryMove);
		bool validateKnight(move_t tryMove);
		bool validateBishop(move_t tryMove);
		chessBoard mBoard;
		vector<move_t> moves;
		chessPiece lastTaken;
		colour_t turn;
		int moveCounter, unsuccesfulMoves;
		char pawnJustMovedW, pawnJustMovedB;

	};

}
#endif /* CHESSGAME_H */

