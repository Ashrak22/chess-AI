/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   chessPiece.cpp
 * Author: Jakub
 * 
 * Created on 16. ledna 2016, 14:15
 */

#include "chessPiece.h"

chessPiece::chessPiece() {
    colour = COLOUR::NONE;
    type = STONES::EMPTY;
}

chessPiece::chessPiece(const chessPiece& orig) {
    this->type = orig.type;
    this->colour = orig.colour;
}

chessPiece::chessPiece(colour_t orig, stones_t stone) {
    colour = orig;
    type = stone;
}

ostream& operator<<(ostream& os, const chessPiece &piece) {
    switch (piece.type) {
        case STONES::BISHOP:
            os << "B";
            break;
        case STONES::EMPTY:
            os << " ";
            break;
        case STONES::KING:
            os << "G";
            break;
        case STONES::KNIGHT:
            os << "K";
            break;
        case STONES::PAWN:
            os << "P";
            break;
        case STONES::QUEEN:
            os << "Q";
            break;
        case STONES::ROOK:
            os << "R";
            break;
    }
}

chessPiece& chessPiece::operator =(const chessPiece& orig)
{
    this->colour = orig.colour;
    this->type = orig.type;
}

void chessPiece::set(colour_t orig, stones_t stone)
{
    colour = orig;
    type = stone;
}

colour_t chessPiece::getColour()
{
    return colour;
}
stones_t chessPiece::getType()
{
    return type;
}
chessPiece::~chessPiece() {
}

ostream& operator<< (ostream& os, colour_t colour)
{
    switch(colour)
    {
        case COLOUR::WHITE:
            os << "WHITE";
            break;
        case COLOUR::BLACK:
            os << "BLACK";
            break;
        default:
            break;
    }
}