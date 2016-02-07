/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jakub
 *
 * Created on 27. prosince 2015, 20:31
 */

#include <cstdlib>
#include "chessBoard.h"
#include "chessGame.h"
#include <chrono>
using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    chessGame test;
    move_t myMove;
    bool ilegal = true;
    while (myMove.from != "end") {
        if(!ilegal) cout << ">> Your last move was illegal!" << endl;
        cout << test;
        cout << "Plese state your move: " << endl;
        cout << ">> ";
        cin >> myMove.from >> myMove.to;
        if (myMove.from == "end") break;
        ilegal = test.move(myMove);
        system("cls");
        //test.print();
        //cout << test;
    }
    return 0;
}

