/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   chessGame.cpp
 * Author: Jakub
 * 
 * Created on 16. ledna 2016, 18:58
 */

#include "chessGame.h"
#include <cstdlib>

chessGame::chessGame() {
    turn = COLOUR::WHITE;
    moveCounter = 0;
    unsuccesfulMoves = 0;
    pawnJustMovedW = 0;
    pawnJustMovedB = 0;
}

bool chessGame::move(move_t tryMove)
{
    chessPiece moved = mBoard.getPiece(tryMove.from);
    bool result;
    unsuccesfulMoves++;
    if(moved.getColour() != turn) return false;
    switch(moved.getType())
    {
        case STONES::ROOK:
            result = this->validateRook(tryMove);
            break;
        case STONES::PAWN:
            result = this->validatePawn(tryMove);
            break;
        case STONES::KNIGHT:
            result = this->validateKnight(tryMove);
            break;
        default:
            return true;
        
    }
    if(!result) return false;
    lastTaken = mBoard.moveStone(tryMove.from, tryMove.to);
    
    unsuccesfulMoves--;
    moves.push_back(tryMove);
    if(turn == COLOUR::WHITE) turn = COLOUR::BLACK;
    else turn = COLOUR::WHITE;
    return true;
}

bool chessGame::validateRook(move_t tryMove)
{
    if(tryMove.from[0] != tryMove.to[0] && tryMove.from[1] != tryMove.to[1]) return false;
    if(mBoard.getPiece(tryMove.from).getColour() == mBoard.getPiece(tryMove.to).getColour()) return false;
    if(tryMove.from[0] == tryMove.to[0])
    {
        if(tryMove.from[1] < tryMove.to[1])
        {
            for(++tryMove.from[1];tryMove.from[1]<tryMove.to[1]; tryMove.from[1]++)
            {
                if(mBoard.getPiece(tryMove.from).getType() != STONES::EMPTY) return false;
            }
        }
        else
        {
            for(--tryMove.from[1];tryMove.from[1]>tryMove.to[1]; tryMove.from[1]--)
            {
                if(mBoard.getPiece(tryMove.from).getType() != STONES::EMPTY) return false;
            }
        }
        
    }
    else if(tryMove.from[1] == tryMove.to[1])
    {
        if(tryMove.from[0] < tryMove.to[0])
        {
            for(++tryMove.from[0];tryMove.from[0]<tryMove.to[0]; tryMove.from[0]++)
            {
                if(mBoard.getPiece(tryMove.from).getType() != STONES::EMPTY) return false;
            }
        }
        else
        {
            for(--tryMove.from[0];tryMove.from[0]>tryMove.to[0]; tryMove.from[0]--)
            {
                if(mBoard.getPiece(tryMove.from).getType() != STONES::EMPTY) return false;
            }
        }
    }
    return true;
}

bool chessGame::validatePawn(move_t tryMove)
{
    if(tryMove.from[0] != tryMove.to[0])
    {
        if(tryMove.from[1] - tryMove.to[1] == 1 || tryMove.from[1] - tryMove.to[1] == - 1)
        {
            if((mBoard.getPiece(tryMove.to).getType() == STONES::EMPTY) ||  
                    (mBoard.getPiece(tryMove.to).getColour() == mBoard.getPiece(tryMove.from).getColour())) return false;
            else return true;
        }
        else return false;
    }
    else if(tryMove.from[1] - tryMove.to[1] == 1 || tryMove.from[1] - tryMove.to[1] == -1)
    {
        if(mBoard.getPiece(tryMove.to).getType() == STONES::EMPTY) return true;
        else return false;
    }
    else if(tryMove.from[1] - tryMove.to[1] == 2 || tryMove.from[1] - tryMove.to[1] == -2)
    {
        if(tryMove.from[1] == '2' || tryMove.from[1] == '7')
            if(mBoard.getPiece(tryMove.to).getType() == STONES::EMPTY) return true;
        return false;
    }
    return false;
}

bool chessGame::validateKnight(move_t tryMove)
{
    if(abs(tryMove.from[0] - tryMove.to[0]) == 2 && abs(tryMove.from[1] - tryMove.to[1]) == 1 &&
            mBoard.getPiece(tryMove.to).getColour() != turn) return true;
    else if(abs(tryMove.from[0] - tryMove.to[0]) == 1 && abs(tryMove.from[1] - tryMove.to[1]) == 2 &&
            mBoard.getPiece(tryMove.to).getColour() != turn) return true;
    return false;
}
chessBoard chessGame::showBoard()
{
    return mBoard;
}
ostream& operator<< (ostream& os, chessGame& game)
{
    os << game.mBoard;
    os << "Turn: " << game.turn << endl;
    os << "Moves: " << game.moves.size() << endl;
    os << "Bad Moves: " << game.unsuccesfulMoves << endl << endl;
    if(game.lastTaken.getType() != STONES::EMPTY)
    {
        cout << game.lastTaken.getColour() << " " << game.lastTaken << " was taken!" << endl;
    }
}


chessGame::chessGame(const chessGame& orig) {
}

chessGame::~chessGame() {
}

