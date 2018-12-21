#include "connect4.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

void terminalPlay(){
    string playerMove = " ";
    string p1 = " ";
    string p2 = " ";
    Board board = getBoard(p1, p2);
    board.prettyPrintBoard(cout);
    cout << "\nEnter: the column to move, q to quit, s to save" << endl;
    if(board.toMove() == 1){
        cout << p1;
    }
    else {
        cout << p2;
    }
    cout <<  " enter your move: ";
    
    while(cin >> playerMove) {
        if (playerMove != "Q" && playerMove != "q" && playerMove != "S" && playerMove != "s" && playerMove != "1" && playerMove != "2" && playerMove != "3" && playerMove != "4" && playerMove != "5" && playerMove != "6" && playerMove != "7") {
            cout << "ILLEGAL MOVE: Try again" << endl;
            cout << "\nEnter: the column to move, q to quit, s to save" << endl;
            if(board.toMove() == 1){
                cout << p1;
            }
            else {
                cout << p2;
            }
            cout <<  " enter your move: ";
        }
        else if (playerMove == "q" || playerMove == "Q"){
            cout << "Thanks for playing!" << endl;
            return;
        }
    
        else if (playerMove == "s" || playerMove == "S"){
            saveBoard(p1, p2, board);
            board.prettyPrintBoard(cout);
            cout << "\nEnter: the column to move, q to quit, s to save" << endl;
            if(board.toMove() == 1){
                cout << p1;
            }
            else {
                cout << p2;
            }
            cout <<  " enter your move: ";
        }
    
        Result gameMove = board.makeMove(stoi(playerMove) - 1);
        
        if (stoi(playerMove) >= 1
            && stoi(playerMove) <= 7
            && gameMove == IllegalMove) {
            cout << "ILLEGAL MOVE: Try again" << endl;
            cout << "\nEnter: the column to move, q to quit, s to save" << endl;
            if(board.toMove() == 1){
                cout << p1;
            }
            else {
                cout << p2;
            }
            cout <<  " enter your move: ";
        }
        else {
            if (gameMove == Win){
                cout << "Congratulations ";
                if (board.toMove() == 1){
                    cout << p2;
                }
                else {
                    cout << p1;
                }
                cout << "! You won!" << endl;
                board.prettyPrintBoard(cout);
                return;
            }
            else if (gameMove == Draw) {
                cout << "Draw!" << endl;
                board.prettyPrintBoard(cout);
                return;
            }
            else if (gameMove == NoResult) {
                board.prettyPrintBoard(cout);
                cout << "\nEnter: the column to move, q to quit, s to save" << endl;
                if (board.toMove() == 1) {
                    cout << p1;
                }
                else if (board.toMove() == 2) {
                    cout << p2;
                }
                cout <<  " enter your move: ";
            }
        }
    }
}

Board getBoard(string &p1, string &p2) {
    string garbage;
    getline(cin, garbage);
    ifstream fileOpener;
    char gameChoice = ' ';
    string filename = " ";
    cout << "Enter L to load a game, or P to play: " << flush;
    cin >> gameChoice;
    if (gameChoice == 'L' || gameChoice == 'l') {
        cout << "Enter the filename: " << flush;
        getline(cin, filename);
        fileOpener.open(filename);
        string boardAsFEN_string;
        getline(fileOpener, p1);
        getline(fileOpener, p2);
        getline(fileOpener, boardAsFEN_string);
        return Board(boardAsFEN_string);
    }
    else {
        getline(cin, garbage);
        cout << "Player 1, enter your name: " << flush;
        getline(cin, p1);
        cout << endl << "Player 2, enter your name: " << flush;
        getline(cin, p2);
        return Board();
    }
}


void saveBoard(string p1, string p2, const Board &board) {
    ofstream gameSaver;
    string filename = " ";
    cout << "Enter the filename: " << flush;
    cin >> filename;
    gameSaver.open(filename);
    gameSaver << p1;
    gameSaver << p2;
    board.printBoard_as_FENstring(gameSaver);
}
