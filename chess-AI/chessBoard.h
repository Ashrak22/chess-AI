/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   board.h
 * Author: Jakub
 *
 * Created on 27. prosince 2015, 20:33
 */

#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <iostream>
#include "chessPiece.h"




class chessBoard {
public:
    chessBoard();
    chessBoard(const chessBoard& orig);
    chessPiece moveStone(std::string from, std::string to);
    friend ostream& operator<< (ostream& os, const chessBoard& Board);
    void printPiece(string where);
    chessPiece getPiece(string where);
    void reset();
    virtual ~chessBoard();
private:
    chessPiece mBoard[8][8];

};

#endif /* BOARD_H */

