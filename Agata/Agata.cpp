#include <iostream>
#include "ChessBoard.h"
#include "Square.h"
#include "utility.h"
#include "knights.h"
#include "pawns.h"
#include "bishops.h"
#include "queens.h"

int main()
{
    ChessBoard c;
    
    c.printBitboard(getQueenAttackMask((int)Square::C5));

    return 0;
}
