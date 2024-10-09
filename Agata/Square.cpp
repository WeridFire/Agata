#include <cstdint>
#include "Square.h"

/*  Pezzi bianchi:
        Pedoni: 2ª riga (riga 1)
        Torri: a1 (0) e h1 (7)
        Cavalli: b1 (1) e g1 (6)
        Alfieri: c1 (2) e f1 (5)
        Regina: d1 (3)
        Re: e1 (4)

    Pezzi neri:
        Pedoni: 7ª riga (riga 6)
        Torri: a8 (56) e h8 (63)
        Cavalli: b8 (57) e g8 (62)
        Alfieri: c8 (58) e f8 (61)
        Regina: d8 (59)
        Re: e8 (60)

*/

//Funzione per passare da uno Square ad una bitboard
uint64_t squareToBitboard(Square square) {
    return 1ULL << static_cast<uint64_t>(square);
}