#include <iostream>
#include "ChessBoard.h"
#include "Square.h"
#include "utility.h"
#include "knights.h"
#include "pawns.h"
#include "slidingpieces.h"

int main(){

    ChessBoard c = ChessBoard();
    c.printBitboard(queen_moves(squareToBitboard(Square::D6) | squareToBitboard(Square::E3), Square::C5));


    return 0;
}
