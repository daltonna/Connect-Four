#include<iostream>
#include "board.h"

using namespace std;

// Test suite for the Board class
// We highly encourage that you implement these functions
// using your test cases for each function to make sure 
// that your Board functions comply RMEs.

void test_default_Constructor();
void test_nondefault_Constructor();
void test_fenString_Constructor();
void test_printBoard_as_FENstring();
void test_toMove();
void test_makeMove();
void test_getFirstFreeRow();
void test_updateToMove();
void test_isBoardFull();
void test_inBounds();
void test_piecesInDirection();
void test_isWin();

Board testBoard;
Board boardOne;
Board boardTwo;
Board boardThree;

//FIX ME: Add values for fen string non-default constructors

int main() {
    test_default_Constructor();
    test_printBoard_as_FENstring();
    test_toMove();
    test_makeMove();
    test_getFirstFreeRow();
    test_updateToMove();
    test_isBoardFull();
    test_inBounds();
    test_piecesInDirection();
    test_isWin();
    return 0;
}


// Sample test case for the default constructor
void test_default_Constructor() {
   cout << "Testing default constructor" << endl;
   Board board;
   board.prettyPrintBoard(cout);
}

void test_nondefault_Constructor() {
    cout << "Testing nondefault constructor" << endl;

    //Board 1 test

    string s1 = "7/7/7/7/7/7 x";
    Board board1(s1);
    board1.prettyPrintBoard(cout);

    //Board 2 test

    string s2 = "2x4/7/7/7/7/7 o";
    Board board2(s2);
    board2.prettyPrintBoard(cout);

    //Board 3 test

    string s3 = "2x1oo1/2x4/7/7/7/7 x";
    Board board3(s3);
    board3.prettyPrintBoard(cout);

}

void test_printBoard_as_FENstring()   {

   

    return;
}

void test_toMove()   {
    cout << "1 for Player 1, 2 for Player 2";
    cout << testBoard.toMove() << " ";
    cout << boardOne.toMove() << " ";
    cout << boardTwo.toMove() << " ";
    cout << boardThree.toMove() << endl;
    testBoard.prettyPrintBoard(cout);
    cout << endl;
    boardOne.prettyPrintBoard(cout);
    cout << endl;
    boardTwo.prettyPrintBoard(cout);
    cout << endl;
    boardThree.prettyPrintBoard(cout);
    cout << endl;
    cout << "End of toMove tests" << endl;
    return;
}

void test_makeMove()   {
    cout << "Testing object: testBoard" << endl;
    cout << testBoard.makeMove(0) << endl;
    cout << testBoard.makeMove(1) << endl;
    cout << testBoard.makeMove(2) << endl;
    cout << testBoard.makeMove(3) << endl;
    cout << testBoard.makeMove(4) << endl;
    cout << testBoard.makeMove(5) << endl;
    cout << testBoard.makeMove(6) << endl;
    cout << testBoard.makeMove(7) << endl;
    cout << testBoard.makeMove(8) << endl;
    cout << "Testing object: boardOne" << endl;
    cout << boardOne.makeMove(0) << endl;
    cout << boardOne.makeMove(1) << endl;
    cout << boardOne.makeMove(2) << endl;
    cout << boardOne.makeMove(3) << endl;
    cout << boardOne.makeMove(4) << endl;
    cout << boardOne.makeMove(5) << endl;
    cout << boardOne.makeMove(6) << endl;
    cout << boardOne.makeMove(7) << endl;
    cout << boardOne.makeMove(8) << endl;
    cout << "Testing object: boardTwo" << endl;
    cout << boardTwo.makeMove(0) << endl;
    cout << boardTwo.makeMove(1) << endl;
    cout << boardTwo.makeMove(2) << endl;
    cout << boardTwo.makeMove(3) << endl;
    cout << boardTwo.makeMove(4) << endl;
    cout << boardTwo.makeMove(5) << endl;
    cout << boardTwo.makeMove(6) << endl;
    cout << boardTwo.makeMove(7) << endl;
    cout << boardTwo.makeMove(8) << endl;
    cout << "Testing object: boardThree" << endl;
    cout << boardThree.makeMove(0) << endl;
    cout << boardThree.makeMove(1) << endl;
    cout << boardThree.makeMove(2) << endl;
    cout << boardThree.makeMove(3) << endl;
    cout << boardThree.makeMove(4) << endl;
    cout << boardThree.makeMove(5) << endl;
    cout << boardThree.makeMove(6) << endl;
    cout << boardThree.makeMove(7) << endl;
    cout << boardThree.makeMove(8) << endl;
    cout << "End of makeMove tests" << endl;
    return;
}

void test_getFirstFreeRow()   {
    cout << "Testing priv function getFirstFreeRow() W/ pub function makeMove" << endl;
    cout << "Testing object: testBoard" << endl;
    cout << testBoard.makeMove(0) << endl;
    cout << testBoard.makeMove(1) << endl;
    cout << testBoard.makeMove(2) << endl;
    cout << testBoard.makeMove(7) << endl;
    cout << "Testing object: boardOne" << endl;
    cout << boardOne.makeMove(0) << endl;
    cout << boardOne.makeMove(1) << endl;
    cout << boardOne.makeMove(3) << endl;
    cout << boardOne.makeMove(7) << endl;
    cout << "Testing object: boardTwo" << endl;
    cout << boardTwo.makeMove(0) << endl;
    cout << boardTwo.makeMove(2) << endl;
    cout << boardTwo.makeMove(3) << endl;
    cout << boardTwo.makeMove(4) << endl;
    cout << boardTwo.makeMove(7) << endl;
    cout << "Testing object: boardThree" << endl;
    cout << boardThree.makeMove(0) << endl;
    cout << boardThree.makeMove(1) << endl;
    cout << boardThree.makeMove(2) << endl;
    cout << boardThree.makeMove(3) << endl;
    cout << boardThree.makeMove(4) << endl;
    cout << boardThree.makeMove(5) << endl;
    cout << boardThree.makeMove(6) << endl;
    cout << boardThree.makeMove(7) << endl;
    cout << boardThree.makeMove(8) << endl;
    cout << "End of getFirstFreeRow tests" << endl;
    return;
}

void test_updateToMove()   {
    cout << "Testing priv function updateToMove W/ pub function makeMove" << endl;
    cout << "Testing object: testBoard" << endl;
    cout << testBoard.makeMove(0) << endl;
    cout << testBoard.makeMove(1) << endl;
    cout << testBoard.makeMove(2) << endl;
    cout << testBoard.makeMove(7) << endl;
    cout << "Testing object: boardOne" << endl;
    cout << boardOne.makeMove(0) << endl;
    cout << boardOne.makeMove(1) << endl;
    cout << boardOne.makeMove(3) << endl;
    cout << boardOne.makeMove(7) << endl;
    cout << "Testing object: boardTwo" << endl;
    cout << boardTwo.makeMove(0) << endl;
    cout << boardTwo.makeMove(2) << endl;
    cout << boardTwo.makeMove(3) << endl;
    cout << boardTwo.makeMove(4) << endl;
    cout << boardTwo.makeMove(7) << endl;
    cout << "Testing object: boardThree" << endl;
    cout << boardThree.makeMove(0) << endl;
    cout << boardThree.makeMove(1) << endl;
    cout << boardThree.makeMove(2) << endl;
    cout << boardThree.makeMove(3) << endl;
    cout << boardThree.makeMove(4) << endl;
    cout << boardThree.makeMove(5) << endl;
    cout << boardThree.makeMove(6) << endl;
    cout << boardThree.makeMove(7) << endl;
    cout << boardThree.makeMove(8) << endl;
    cout << "End of updateToMove tests" << endl;
    return;
}

void test_isBoardFull()   {
    cout << "Testing priv function isBoardFull W/ pub function makeMove" << endl;
    cout << "Testing object: testBoard" << endl;
    cout << testBoard.makeMove(0) << endl;
    cout << testBoard.makeMove(1) << endl;
    cout << testBoard.makeMove(2) << endl;
    cout << testBoard.makeMove(7) << endl;
    cout << "Testing object: boardOne" << endl;
    cout << boardOne.makeMove(0) << endl;
    cout << boardOne.makeMove(1) << endl;
    cout << boardOne.makeMove(3) << endl;
    cout << boardOne.makeMove(7) << endl;
    cout << "Testing object: boardTwo" << endl;
    cout << boardTwo.makeMove(0) << endl;
    cout << boardTwo.makeMove(2) << endl;
    cout << boardTwo.makeMove(3) << endl;
    cout << boardTwo.makeMove(4) << endl;
    cout << boardTwo.makeMove(7) << endl;
    cout << "Testing object: boardThree" << endl;
    cout << boardThree.makeMove(0) << endl;
    cout << boardThree.makeMove(1) << endl;
    cout << boardThree.makeMove(2) << endl;
    cout << boardThree.makeMove(3) << endl;
    cout << boardThree.makeMove(4) << endl;
    cout << boardThree.makeMove(5) << endl;
    cout << boardThree.makeMove(6) << endl;
    cout << boardThree.makeMove(7) << endl;
    cout << boardThree.makeMove(8) << endl;
    cout << "End of isBoardFull tests" << endl;
    return;
}

void test_inBounds()   {
    return;
}

void test_piecesInDirection()   {
    
    return;
}

void test_isWin()   {
    return;
}



















