/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   chessPiece.h
 * Author: Jakub
 *
 * Created on 16. ledna 2016, 14:15
 */

#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <ostream>
using namespace std;

namespace chessAI
{
	public enum class STONES
	{
		PAWN,
		KNIGHT,
		BISHOP,
		ROOK,
		QUEEN,
		KING,
		EMPTY
	} typedef stones_t;

	public enum class COLOUR
	{
		BLACK,
		WHITE,
		NONE
	} typedef colour_t;

	ostream& operator<< (ostream& os, colour_t);
	
	class chessPiece {
	public:
		chessPiece();
		chessPiece(const chessPiece& orig);
		chessPiece(colour_t orig, stones_t stone);
		colour_t getColour();
		stones_t getType();
		void set(colour_t orig, stones_t stone);
		chessPiece& operator=(const chessPiece& orig);
		friend ostream& operator<<(ostream& os, const chessPiece &piece);
		void clear();
		virtual ~chessPiece();
	private:
		colour_t colour;
		stones_t type;

	};
}
#endif /* CHESSPIECE_H */

