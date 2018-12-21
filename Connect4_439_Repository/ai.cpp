#include "ai.h"
#include "board.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//AI alsways goes second
int closestToMiddle(const Board &board);
int checkForOurConsecutiveWin(const Board& board);
int checkForOurNonConsecutiveWin(const Board& board);
int blockOpponentWin(const Board& board);
int blockOpponentTwoInARow(const Board& board);
int makeOurThreeInARow(const Board& board);
int blockOpponentNonConsecutiveWin(const Board& board);
int makeTwoInARow(const Board &board);
int makeNonConsecutiveThreeInARow(const Board &board);
int blockNonConsecutiveThreeInARow(const Board &board);
int columnOffLimits(const Board& board);
int connect4AI(const Board& board){
    clock_t t;
    t = clock();
    t = clock() - t;
    if (checkForOurConsecutiveWin(board) != NUM_COLS){
        return checkForOurConsecutiveWin(board);
    }
    else if (checkForOurNonConsecutiveWin(board) != NUM_COLS){
        return checkForOurNonConsecutiveWin(board);
    }
    else if (blockOpponentWin(board) != NUM_COLS) {
            return blockOpponentWin(board);
    }
    else if (blockOpponentNonConsecutiveWin(board) != NUM_COLS){
        int test_block = blockOpponentNonConsecutiveWin(board);
        return test_block;
    }
    else if (blockOpponentTwoInARow(board) != NUM_COLS){
        return blockOpponentTwoInARow(board);
    }
    else if (blockNonConsecutiveThreeInARow(board) != NUM_COLS){
            return blockNonConsecutiveThreeInARow(board);
    }
    else if (makeOurThreeInARow(board) != NUM_COLS){
            return makeOurThreeInARow(board);
    }
    else if (makeNonConsecutiveThreeInARow(board) != NUM_COLS){
            return makeNonConsecutiveThreeInARow(board);
    }
    else if (makeTwoInARow(board) != NUM_COLS){
            return makeTwoInARow(board);
    }
    return closestToMiddle(board);
}


int checkForOurConsecutiveWin(const Board& board){
    Board newBoard = board;
    for (int row = 0 ; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            if (newBoard.atLocation(row, col) == Player2) {
                if (board.piecesInDirection(row, col, 0, 1) == 2) {
                    if (newBoard.atLocation(row, col + 3) == Empty
                        && row == board.getFirstFreeRow(col + 3))   {
                        if (board.inBounds((row), (col + 3))) {
                            return (col + 3);
                        }
                    }
                }
                if (newBoard.piecesInDirection(row, col, 0, -1) ==2 ) {
                    if (newBoard.atLocation(row, col - 3) == Empty
                        && row == board.getFirstFreeRow(col - 3)){
                        if (board.inBounds((row), (col - 3))) {
                            return (col - 3);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, 1, 0) == 2 ) {
                    if (newBoard.atLocation(row + 3, col) == Empty) {
                        if (board.inBounds((row + 3), (col))) {
                            return (col);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, 1, 1) == 2) {
                    if ((newBoard.atLocation(row + 3, col + 3) == Empty)
                        && (row + 3) == (board.getFirstFreeRow(col + 3))) {
                        if (board.inBounds((row + 3), (col + 3))) {
                            return (col + 3);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, -1, -1) == 2 ) {
                    if (((newBoard.atLocation(row - 3, col - 3) == Empty)) && ((row - 3) == board.getFirstFreeRow(col - 3))) {
                        if (board.inBounds((row - 3), (col - 3))) {
                            return (col - 3);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, 1, -1) == 2) {
                    if (((newBoard.atLocation(row + 3, col - 3) == Empty)) && (row + 3) == (board.getFirstFreeRow(col - 3))) {
                        if (board.inBounds((row + 3), (col - 3))) {
                            return (col - 3);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, -1, 1) == 2) {
                    if (((newBoard.atLocation(row - 3, col + 3) == Empty) && (row - 3) == (board.getFirstFreeRow(col + 3)))) {
                        if (board.inBounds((row - 3), (col + 3))) {
                            return (col + 3);
                        }
                    }
                }
            }
        }
    }
    return NUM_COLS;
}

int blockOpponentWin(const Board& board){
    Board newBoard = board;
    for (int row = 0 ; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            if (newBoard.atLocation(row, col) == Player1) {
                if (board.piecesInDirection(row, col, 0, 1) == 2) {
                    if (newBoard.atLocation(row, col + 3) == Empty
                        && row == board.getFirstFreeRow(col + 3))   {
                        if (board.inBounds((row), (col + 3))) {
                            return (col + 3);
                        }
                    }
                }
                if (newBoard.piecesInDirection(row, col, 0, -1) ==2 ) {
                    if (newBoard.atLocation(row, col - 3) == Empty
                        && row == board.getFirstFreeRow(col - 3)){
                        if (board.inBounds((row), (col - 3))) {
                            return (col - 3);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, 1, 0) == 2 ) {
                    if (newBoard.atLocation(row + 3, col) == Empty) {
                        if (board.inBounds((row + 3), (col))) {
                            return (col);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, 1, 1) == 2) {
                    if ((newBoard.atLocation(row + 3, col + 3) == Empty)
                        && (row + 3) == (board.getFirstFreeRow(col + 3))) {
                        if (board.inBounds((row + 3), (col + 3))) {
                            return (col + 3);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, -1, -1) == 2 ) {
                    if (((newBoard.atLocation(row - 3, col - 3) == Empty)) && ((row - 3) == board.getFirstFreeRow(col - 3))) {
                        if (board.inBounds((row - 3), (col - 3))) {
                            return (col - 3);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, 1, -1) == 2) {
                    if (((newBoard.atLocation(row + 3, col - 3) == Empty)) && (row + 3) == (board.getFirstFreeRow(col - 3))) {
                        if (board.inBounds((row + 3), (col - 3))) {
                            return (col - 3);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, -1, 1) == 2) {
                    if (((newBoard.atLocation(row - 3, col + 3) == Empty) && (row - 3) == (board.getFirstFreeRow(col + 3)))) {
                        if (board.inBounds((row - 3), (col + 3))) {
                            return (col + 3);
                        }
                    }
                }
            }
        }
    }
    return NUM_COLS;
}

int blockOpponentTwoInARow(const Board& board){
    Board newBoard = board;
    for (int row = 0 ; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            if (newBoard.atLocation(row, col) == Player1) {
                if (board.piecesInDirection(row, col, 0, 1) == 1) {
                    if (newBoard.atLocation(row, col + 2) == Empty
                        && row == board.getFirstFreeRow(col + 2))   {
                        if (board.inBounds((row), (col + 2))) {
                            return (col + 2);
                        }
                    }
                }
                if (newBoard.piecesInDirection(row, col, 0, -1) == 1 ) {
                    if (newBoard.atLocation(row, col - 2) == Empty
                        && row == board.getFirstFreeRow(col - 2)){
                        if (board.inBounds((row), (col - 2))) {
                            return (col - 2);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, 1, 0) == 1 ) {
                    if (newBoard.atLocation(row + 2, col) == Empty) {
                        if (board.inBounds((row + 2), (col))) {
                            return (col);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, 1, 1) == 1) {
                    if ((newBoard.atLocation(row + 2, col + 2) == Empty)
                        && (row + 2) == (board.getFirstFreeRow(col + 2))) {
                        if (board.inBounds((row + 2), (col + 2))) {
                            return (col + 2);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, -1, -1) == 1 ) {
                    if (((newBoard.atLocation(row - 2, col - 2) == Empty)) && ((row - 2) == board.getFirstFreeRow(col - 2))) {
                        if (board.inBounds((row - 2), (col - 2))) {
                            return (col - 2);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, 1, -1) == 1) {
                    if (((newBoard.atLocation(row + 2, col - 2) == Empty)) && (row + 2) == (board.getFirstFreeRow(col - 2))) {
                        if (board.inBounds((row + 2), (col - 2))) {
                            return (col - 2);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, -1, 1) == 1) {
                    if (((newBoard.atLocation(row - 2, col + 2) == Empty) && (row - 2) == (board.getFirstFreeRow(col + 2)))) {
                        if (board.inBounds((row - 2), (col + 2))) {
                            return (col + 2);
                        }
                    }
                }
            }
        }
    }
    return NUM_COLS;
}

int makeOurThreeInARow(const Board& board){
    Board newBoard = board;
    for (int row = 0 ; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            if (newBoard.atLocation(row, col) == Player2) {
                if (board.piecesInDirection(row, col, 0, 1) == 1) {
                    if (newBoard.atLocation(row, col + 2) == Empty
                        && row == board.getFirstFreeRow(col + 2))   {
                        if (board.inBounds((row), (col + 2))) {
                            return (col + 2);
                        }
                    }
                }
                if (newBoard.piecesInDirection(row, col, 0, -1) == 1 ) {
                    if (newBoard.atLocation(row, col - 2) == Empty
                        && row == board.getFirstFreeRow(col - 2)){
                        if (board.inBounds((row), (col - 2))) {
                            return (col - 2);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, 1, 0) == 1 ) {
                    if (newBoard.atLocation(row + 2, col) == Empty) {
                        if (board.inBounds((row + 2), (col))) {
                            return (col);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, 1, 1) == 1) {
                    if ((newBoard.atLocation(row + 2, col + 2) == Empty)
                        && (row + 2) == (board.getFirstFreeRow(col + 2))) {
                        if (board.inBounds((row + 2), (col + 2))) {
                            return (col + 2);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, -1, -1) == 1 ) {
                    if (((newBoard.atLocation(row - 2, col - 2) == Empty)) && ((row - 2) == board.getFirstFreeRow(col - 2))) {
                        if (board.inBounds((row - 2), (col - 2))) {
                            return (col - 2);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, 1, -1) == 1) {
                    if (((newBoard.atLocation(row + 2, col - 2) == Empty)) && (row + 2) == (board.getFirstFreeRow(col - 2))) {
                        if (board.inBounds((row + 2), (col - 2))) {
                            return (col - 2);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, -1, 1) == 1) {
                    if (((newBoard.atLocation(row - 2, col + 2) == Empty) && (row - 2) == (board.getFirstFreeRow(col + 2)))) {
                        if (board.inBounds((row - 2), (col + 2))) {
                            return (col + 2);
                        }
                    }
                }
            }
        }
    }
    return NUM_COLS;
}



int checkForOurNonConsecutiveWin(const Board& board){
    Board newBoard = board;
    for (int row = 0 ; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            if (newBoard.atLocation(row, col) == Player2) {
                if (board.piecesInDirection(row, col, 0, 1) == 1) {
                    if (newBoard.atLocation(row, col + 3) == Player2
                        && newBoard.atLocation(row, col + 2) == Empty && row == board.getFirstFreeRow(col + 2))   {
                        if (board.inBounds((row), (col + 2))) {
                            return (col + 2);
                        }
                    }
                }
                if (newBoard.piecesInDirection(row, col, 0, -1) == 1 ) {
                    if (newBoard.atLocation(row, col - 3) == Player2
                        && newBoard.atLocation(row, col - 2) == Empty
                        && row == board.getFirstFreeRow(col - 2)){
                        if (board.inBounds((row + 2), (col - 2))) {
                            return (col - 2);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, 1, 1) == 1) {
                    if ((newBoard.atLocation(row + 3, col + 3) == Player2)
                        && newBoard.atLocation(row + 2, col + 2) == Empty
                        && (row + 2) == (board.getFirstFreeRow(col + 2))) {
                        if (board.inBounds((row + 2), (col + 2))) {
                            return (col + 2);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, -1, -1) == 1 ) {
                    if (((newBoard.atLocation(row - 3, col - 3) == Player2))
                        && newBoard.atLocation(row - 2, col - 2) == Empty
                        && ((row - 2) == board.getFirstFreeRow(col - 2))) {
                        if (board.inBounds((row - 2), (col - 2))) {
                            return (col - 2);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, 1, -1) == 1) {
                    if (((newBoard.atLocation(row + 3, col - 3) == Player2)) &&
                        newBoard.atLocation(row + 2 , col - 2) == Empty &&
                        (row + 2) == (board.getFirstFreeRow(col - 2))) {
                        if (board.inBounds((row + 2), (col - 2))) {
                            return (col - 2);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, -1, 1) == 1) {
                    if (((newBoard.atLocation(row - 3, col + 3) == Player2) &&
                         newBoard.atLocation(row - 2, col + 2) == Empty &&
                         (row - 2) == (board.getFirstFreeRow(col + 2)))) {
                        if (board.inBounds((row - 2), (col + 2))) {
                            return (col + 2);
                        }
                    }
                }
            }
        }
    }
    return NUM_COLS;
}

int blockOpponentNonConsecutiveWin(const Board& board){
    Board newBoard = board;
    for (int row = 0 ; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            if (newBoard.atLocation(row, col) == Player1) {
                if (board.piecesInDirection(row, col, 0, 1) == 1) {
                    if (newBoard.atLocation(row, col + 3) == Player1
                        && newBoard.atLocation(row, col + 2) == Empty && row == board.getFirstFreeRow(col + 2))   {
                        return (col + 2);
                    }
                }
                if (newBoard.piecesInDirection(row, col, 0, -1) == 1 ) {
                    if (newBoard.atLocation(row, col - 3) == Player1
                        && newBoard.atLocation(row, col - 2) == Empty
                        && row == board.getFirstFreeRow(col - 2)){
                        if (board.inBounds(row, col - 2)) {
                            return (col - 2);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, 1, 1) == 1) {
                    if ((newBoard.atLocation(row + 3, col + 3) == Player1)
                        && newBoard.atLocation(row + 2, col + 2) == Empty
                        && (row + 2) == (board.getFirstFreeRow(col + 2))) {
                        if (board.inBounds((row + 2), (col + 2))) {
                            return (col + 2);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, -1, -1) == 1 ) {
                    if (((newBoard.atLocation(row - 3, col - 3) == Player1))
                        && newBoard.atLocation(row - 2, col - 2) == Empty
                        && ((row - 2) == board.getFirstFreeRow(col - 2))) {
                        if (board.inBounds((row - 2), (col - 2))) {
                            return (col - 2);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, 1, -1) == 1) {
                    if (((newBoard.atLocation(row + 3, col - 3) == Player1)) &&
                        newBoard.atLocation(row + 2 , col - 2) == Empty &&
                        (row + 2) == (board.getFirstFreeRow(col - 2))) {
                        if (board.inBounds((row + 2), (col - 2))) {
                            return (col - 2);
                        }
                    }
                }
                if (board.piecesInDirection(row, col, -1, 1) == 1) {
                    if (((newBoard.atLocation(row - 3, col + 3) == Player1) &&
                         newBoard.atLocation(row - 2, col + 2) == Empty &&
                         (row - 2) == (board.getFirstFreeRow(col + 2)))) {
                        if (board.inBounds((row - 2), (col + 2))) {
                            return (col + 2);
                        }
                    }
                }
            }
        }
    }
    return NUM_COLS;
}

int makeTwoInARow(const Board &board){
    Board newBoard = board;
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            if ((newBoard.atLocation(row, col) == Player2)
                && (board.piecesInDirection(row, col, 0, 1) == 0)
                && (newBoard.atLocation(row, col + 1)) == Empty
                && (row == board.getFirstFreeRow(col + 1))){
                if (board.inBounds((row), (col + 1))) {
                    return (col + 1);
                }
            }
            if ((newBoard.atLocation(row, col) == Player2)
                && (board.piecesInDirection(row, col, 0, -1) == 0)
                && (newBoard.atLocation(row, col - 1)) == Empty
                && (row == board.getFirstFreeRow(col - 1))){
                if (board.inBounds((row), (col - 1))) {
                    return (col - 1);
                }
            }
            if ((newBoard.atLocation(row, col) == Player2)
                && (board.piecesInDirection(row, col, 1, 0) == 0)
                && (newBoard.atLocation(row + 1, col)) == Empty){
                if (board.inBounds((row + 1), (col))) {
                    return (col);
                }
            }
            if ((newBoard.atLocation(row, col) == Player2)
                && (board.piecesInDirection(row, col, 1, 1) == 0)
                && (newBoard.atLocation(row + 1, col + 1)) == Empty
                && ((row + 1) == board.getFirstFreeRow(col + 1))){
                if (board.inBounds((row + 1), (col + 1))) {
                    return (col + 1);
                }
            }
            if ((newBoard.atLocation(row, col) == Player2)
                && (board.piecesInDirection(row, col, -1, -1) == 0)
                && (newBoard.atLocation(row - 1, col - 1)) == Empty
                && ((row - 1) == board.getFirstFreeRow(col - 1))){
                if (board.inBounds((row - 1), (col - 1))) {
                    return (col - 1);
                }
            }
            if ((newBoard.atLocation(row, col) == Player2)
                && (board.piecesInDirection(row, col, 1, -1) == 0)
                && (newBoard.atLocation(row + 1, col - 1)) == Empty
                && ((row + 1) == board.getFirstFreeRow(col - 1))){
                if (board.inBounds((row + 1), (col - 1))) {
                    return (col - 1);
                }
            }
            if ((newBoard.atLocation(row, col) == Player2)
                && (board.piecesInDirection(row, col, -1, 1) == 0)
                && (newBoard.atLocation(row - 1, col + 1)) == Empty
                && ((row - 1) == board.getFirstFreeRow(col + 1))){
                if (board.inBounds((row - 1), (col + 1))) {
                    return (col + 1);
                }
            }
        }
    }
    return NUM_COLS;
}

int makeNonConsecutiveThreeInARow(const Board &board){
    Board newBoard = board;
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            if ((newBoard.atLocation(row, col) == Player2)
                && (board.piecesInDirection(row, col, 0, 1) == 0)
                && (newBoard.atLocation(row, col + 2) == Player2)
                && (newBoard.atLocation(row, col + 1)) == Empty
                && (row == board.getFirstFreeRow(col + 1))){
                if (board.inBounds((row), (col + 1))) {
                    return (col + 1);
                }
            }
            if ((newBoard.atLocation(row, col) == Player2)
                && (board.piecesInDirection(row, col, 0, -1) == 0)
                && (newBoard.atLocation(row, col - 2) == Player2)
                && (newBoard.atLocation(row, col - 1)) == Empty
                && (row == board.getFirstFreeRow(col - 1))){
                if (board.inBounds((row), (col - 1))) {
                    return (col - 1);
                }
            }
            if ((newBoard.atLocation(row, col) == Player2)
                && (board.piecesInDirection(row, col, 1, 0) == 0)
                && (newBoard.atLocation(row + 1, col)) == Empty){
                if (board.inBounds((row + 1), (col))) {
                    return (col);
                }
            }
            if ((newBoard.atLocation(row, col) == Player2)
                && (board.piecesInDirection(row, col, 1, 1) == 0)
                && (newBoard.atLocation(row + 2, col + 2) == Player2)
                && (newBoard.atLocation(row + 1, col + 1)) == Empty
                && ((row + 1) == board.getFirstFreeRow(col + 1))){
                if (board.inBounds((row + 1), (col + 1))) {
                    return (col + 1);
                }
            }
            if ((newBoard.atLocation(row, col) == Player2)
                && (board.piecesInDirection(row, col, -1, -1) == 0)
                && (newBoard.atLocation(row - 2, col - 2) == Player2)
                && (newBoard.atLocation(row - 1, col - 1)) == Empty
                && ((row - 1) == board.getFirstFreeRow(col - 1))){
                if (board.inBounds((row - 1), (col - 1))) {
                    return (col - 1);
                }
            }
            if ((newBoard.atLocation(row, col) == Player2)
                && (board.piecesInDirection(row, col, 1, -1) == 0)
                && (newBoard.atLocation(row + 2, col - 2) == Player2)
                && (newBoard.atLocation(row + 1, col - 1)) == Empty
                && ((row + 1) == board.getFirstFreeRow(col - 1))){
                if (board.inBounds((row + 1), (col - 1))) {
                    return (col - 1);
                }
            }
            if ((newBoard.atLocation(row, col) == Player2)
                && (board.piecesInDirection(row, col, -1, 1) == 0)
                && (newBoard.atLocation(row - 2, col + 2) == Player2)
                && (newBoard.atLocation(row - 1, col + 1)) == Empty
                && ((row - 1) == board.getFirstFreeRow(col + 1))){
                if (board.inBounds((row - 1), (col + 1))) {
                    return (col + 1);
                }
            }
        }
    }
    return NUM_COLS;
}


int blockNonConsecutiveThreeInARow(const Board &board){
    Board newBoard = board;
    for (int row = 0; row < NUM_ROWS; row++) {
        for (int col = 0; col < NUM_COLS; col++) {
            if ((newBoard.atLocation(row, col) == Player1)
                && (board.piecesInDirection(row, col, 0, 1) == 0)
                && (newBoard.atLocation(row, col + 2) == Player1)
                && (newBoard.atLocation(row, col + 1)) == Empty
                && (row == board.getFirstFreeRow(col + 1))){
                if (board.inBounds((row), (col + 1))) {
                    return (col + 1);
                }
            }
            if ((newBoard.atLocation(row, col) == Player1)
                && (board.piecesInDirection(row, col, 0, -1) == 0)
                && (newBoard.atLocation(row, col - 2) == Player1)
                && (newBoard.atLocation(row, col - 1)) == Empty
                && (row == board.getFirstFreeRow(col - 1))){
                if (board.inBounds((row), (col - 1))) {
                    return (col - 1);
                }
            }
            if ((newBoard.atLocation(row, col) == Player1)
                && (board.piecesInDirection(row, col, 1, 0) == 0)
                && (newBoard.atLocation(row + 1, col)) == Empty
                && ((row + 1) == board.getFirstFreeRow(col))){
                if (board.inBounds((row + 1), (col))) {
                    return (col);
                }
            }
            if ((newBoard.atLocation(row, col) == Player1)
                && (board.piecesInDirection(row, col, 1, 1) == 0)
                && (newBoard.atLocation(row + 2, col + 2) == Player1)
                && (newBoard.atLocation(row + 1, col + 1)) == Empty
                && ((row + 1) == board.getFirstFreeRow(col + 1))){
                if (board.inBounds((row + 1), (col + 1))) {
                    return (col + 1);
                }
            }
            if ((newBoard.atLocation(row, col) == Player1)
                && (board.piecesInDirection(row, col, -1, -1) == 0)
                && (newBoard.atLocation(row - 2, col - 2) == Player1)
                && (newBoard.atLocation(row - 1, col - 1)) == Empty
                && ((row - 1) == board.getFirstFreeRow(col - 1))){
                if (board.inBounds((row - 1), (col - 1))) {
                    return (col - 1);
                }
            }
            if ((newBoard.atLocation(row, col) == Player1)
                && (board.piecesInDirection(row, col, 1, -1) == 0)
                && (newBoard.atLocation(row + 2, col - 2) == Player1)
                && (newBoard.atLocation(row + 1, col - 1)) == Empty
                && ((row + 1) == board.getFirstFreeRow(col - 1))){
                if (board.inBounds((row + 1), (col - 1))) {
                    return (col - 1);
                }
            }
            if ((newBoard.atLocation(row, col) == Player1)
                && (board.piecesInDirection(row, col, -1, 1) == 0)
                && (newBoard.atLocation(row - 2, col + 2) == Player1)
                && (newBoard.atLocation(row - 1, col + 1)) == Empty
                && ((row - 1) == board.getFirstFreeRow(col + 1))){
                if (board.inBounds((row - 1), (col + 1))) {
                    return (col + 1);
                }
            }
        }
    }
    return NUM_COLS;
}


int closestToMiddle(const Board &board){
    if (board.getFirstFreeRow(3) != NUM_ROWS) {
        return 3;
    }
    else if (board.getFirstFreeRow(2) != NUM_ROWS){
        return 2;
    }
    else if (board.getFirstFreeRow(4) != NUM_ROWS){
        return 4;
    }
    else if (board.getFirstFreeRow(1) != NUM_ROWS){
        return 1;
    }
    else if (board.getFirstFreeRow(5) != NUM_ROWS){
        return 5;
    }
    else if (board.getFirstFreeRow(0) != NUM_ROWS){
        return 0;
    }
    else if (board.getFirstFreeRow(6) != NUM_ROWS){
        return 6;
    }
    return 0;
}


    
    










