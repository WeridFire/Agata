#include <iostream>
#include "ChessBoard.h"
#include "Square.h"
#include "utility.h"
#include "knights.h"
#include "pawns.h"

int main()
{
    ChessBoard c;
    
    c.printBitboard(getKnightMoves(c.whiteKnights));

    return 0;
}
