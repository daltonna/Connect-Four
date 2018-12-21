#include "board.h"
#include <string>
#include <iostream>
using namespace std;


Board::Board() {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            data[i][j] = Empty;
        }
    }
    nextPlayer_to_move = Player1;
}

Board::Board(const string &fen) {
    
    int col = 0;
    int row = 0;
    //goes through the fen string of moves before next player
    for (int i = 0; i < (fen.size() - 2); i++) {
        if (fen[i] == PLAYER1_TOKEN) {
            //if there's an x, marks board with x
            data[row][col] = Player1;
            //moves on to next column within row
            col++;
        }
        else if (fen[i] == PLAYER2_TOKEN) {
            //if there's an o, sets index to player 2
            data[row][col] = Player2;
            col++;
        }
        //moves to the next row as indicated by slash
        else if (fen[i] == '/') {
            row++;
            col = 0;
        }
        else {
            //converts char into int to use as count control
            int spaces = (fen[i] - 48);
            //marks indexes as empty depending on int
            for (int j = 0; j < spaces; j++) {
                data[row][col] = Empty;
                col++;
            }
        }
    }
    //looks at the last character of fen string
    if (fen[fen.size() - 1] == PLAYER1_TOKEN) {
        //if last character is x, next move is on player 1
        nextPlayer_to_move = Player1;
    }
    else if (fen[fen.size() - 1] == PLAYER2_TOKEN) {
        //if last character is o, next move is player 2
        nextPlayer_to_move = Player2;
    }
}
    
void Board::printBoard_as_FENstring(ostream &os) const {

    int row = 0;
    int col = 0;
    int spaceCounter;

    // re-sets counter of spaces to 0 for each row
    for (row = 0; row < NUM_ROWS; row++) {
        spaceCounter = 0;

        for (col = 0; col < NUM_COLS; col++) {
            if (data[row][col] == Empty) {
                spaceCounter++;
            }
            else if (data[row][col] == Player1) {
                if (spaceCounter > 0) {
                    os << spaceCounter;
                    spaceCounter = 0;
                }
                os << PLAYER1_TOKEN;               
            }
            else if (data[row][col] == Player2) {
                if (spaceCounter > 0) {
                    os << spaceCounter;
                    spaceCounter = 0;
                }
                os << PLAYER2_TOKEN;                
            }
            if (col == (NUM_COLS - 1)) {
                os << spaceCounter;
                spaceCounter = 0;
            }

        }
        if (row < (NUM_ROWS - 1)) {
            os << '/';
        }
    }
    os << ' ';

    if (nextPlayer_to_move == Player1) {
        os << PLAYER1_TOKEN;
    }
    else if (nextPlayer_to_move == Player2) {
        os << PLAYER2_TOKEN;
    }
}      

PieceType Board::atLocation(int row, int col) {
    return data[row][col];
}

void Board::prettyPrintBoard(ostream &os) const {
	os << endl;
    for (int row = NUM_ROWS - 1; row >= 0; row--)  {
        os << "     +---+---+---+---+---+---+---+"
           << endl
           << "    ";
        
        for (int col = 0; col < NUM_COLS; col++)   {
            os << " | " ;
            if ( data[row][col] == Player1)
                os <<  PLAYER1_TOKEN;
            else if (data[row][col] == Player2)
                os << PLAYER2_TOKEN;
            else
                os << EMPTY_TOKEN;
        }
        os << " |" << endl;
    }
    os << "     +---+---+---+---+---+---+---+" << endl
       <<"  col  1   2   3   4   5   6   7" << endl;
    return;
}

int Board::toMove() const {
    if (nextPlayer_to_move == Player2) {
        return 2;
    }
    else {
        return 1;
    }
}

Result Board::makeMove(int col) {
    int row = getFirstFreeRow(col);
    if (inBounds(getFirstFreeRow(col), col)){
        data[getFirstFreeRow(col)][col] = nextPlayer_to_move;
        updateToMove();
    
        if (isBoardFull()) {
            return Draw;
        }
    
        else if (row == NUM_ROWS){
            return IllegalMove;
        }
    
        else if (!inBounds(row, col)) {
            return IllegalMove;
        }
    
        else if (isWin(row, col)) {
            return Win;
        }
    
        else{
            return NoResult;
        }
    }
    return NoResult;
}

int Board::getFirstFreeRow(int col) const {
    for (int i = 0; i < NUM_ROWS; i++) {
        if (data[i][col] == Empty) {
            return i;
        }
    }
    return NUM_ROWS;
}

PieceType Board::updateToMove() {
    if (nextPlayer_to_move == Player2){
        nextPlayer_to_move = Player1;
        return Player2;
    }
    else {
        nextPlayer_to_move = Player2;
        return Player1;
    }
}

bool Board::isBoardFull() const {
    for (int i = 0; i < NUM_ROWS; i++){
        for (int j = 0; j < NUM_COLS; j++) {
            if (data[i][j] == Empty){
                return false;
            }
        }
    }
    return true;
}


bool Board::inBounds(int row, int col) const {
    if ((row >= 0 && row < NUM_ROWS ) &&
        (col >= 0 && col < NUM_COLS)) {
        return true;
    }
    return false;
}

int Board::piecesInDirection(int row, int col, int dRow, int dCol) const {
    int samePieceCount = 0;
    PieceType playerToken = data[row][col];
    while (data[row + dRow][col + dCol] == playerToken &&
           inBounds(row + dRow, col +dCol)) {
        samePieceCount++;
        row += dRow;
        col += dCol;
    }
    return samePieceCount;
}
    

bool Board::isWin(int row, int col) const {
   if (data[row][col] != Empty) {
         // checking for all options in a row
        if (piecesInDirection(row, col, 0, 1) == 3) {
            return true;
        }
    
        else if (piecesInDirection(row, col, 0, -1) == 3) {
            return true;
        }
    
        else if (piecesInDirection(row, col, 0, -1) + piecesInDirection(row, col, 0, 1) >= 3) {
            return true;
        }
        // checking for all options in a column
        else if (piecesInDirection(row, col, -1, 0) == 3) {
            return true;
        }
        // checking for all options in a right diagonal
        else if (piecesInDirection(row, col, 1, 1) == 3) {
            return true;
        }
    
        else if (piecesInDirection(row, col, -1, -1) == 3) {
            return true;
        }
        else if (piecesInDirection(row, col, 1, 1) + piecesInDirection(row, col, -1, -1) >= 3){
            return true;
        }
        // checking for all options
        else if (piecesInDirection(row, col, -1, 1) == 3) {
            return true;
        }
    
        else if (piecesInDirection(row, col, 1, -1) == 3) {
            return true;
        }
    
        else if (piecesInDirection(row, col, 1, -1) + piecesInDirection(row, col, -1, 1) >= 3){
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}


