#pragma once
#include <cstdint>

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

enum class Square : int {
    A1 = 0, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8
};

// Dichiarazione della funzione
uint64_t squareToBitboard(Square square);

inline int toInt(Square sq);
