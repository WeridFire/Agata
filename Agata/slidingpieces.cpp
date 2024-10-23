#include "slidingpieces.h"

uint64_t bishop_moves(uint64_t occupancy, Square square) {
    uint64_t attacks = 0;

    // Tabelle di direzioni per il movimento diagonale dell'alfiere
    const int directions[4] = { 9, 7, -9, -7 };  // Diagonali: SE, SW, NE, NW

    for (int i = 0; i < 4; i++) {
        int direction = directions[i];
        int sq = (int)square;

        // Muovi l'alfiere nella direzione corrente fino ai limiti della scacchiera o a un'occupazione
        while (true) {
            sq += direction;

            // Controllo dei limiti della scacchiera (se sq è fuori dalla scacchiera)
            if (sq < 0 || sq >= 64 || (direction == 9 && sq % 8 == 0) || (direction == 7 && sq % 8 == 7) ||
                (direction == -9 && sq % 8 == 7) || (direction == -7 && sq % 8 == 0)) {
                break;
            }

            attacks |= (1ULL << sq);  // Settiamo il bit della casella di destinazione

            // Se c'è un pezzo in questa casella, l'alfiere non può andare oltre
            if (occupancy & (1ULL << sq)) {
                break;
            }
        }
    }

    return attacks;
}

uint64_t rook_moves(uint64_t occupancy, Square square) {
    uint64_t attacks = 0;

    // Tabelle di direzioni per il movimento della torre
    const int directions[4] = { 8, -8, 1, -1 };  // Direzioni: Nord, Sud, Est, Ovest

    for (int i = 0; i < 4; i++) {
        int direction = directions[i];
        int sq = (int)square;

        // Muovi la torre nella direzione corrente fino ai limiti della scacchiera o a un'occupazione
        while (true) {
            sq += direction;

            // Controllo dei limiti della scacchiera (se sq è fuori dalla scacchiera)
            if (sq < 0 || sq >= 64 ||
                (direction == 1 && sq % 8 == 0) ||  // Limite file destra (Est)
                (direction == -1 && sq % 8 == 7)) { // Limite file sinistra (Ovest)
                break;
            }

            attacks |= (1ULL << sq);  // Settiamo il bit della casella di destinazione

            // Se c'è un pezzo in questa casella, la torre non può andare oltre
            if (occupancy & (1ULL << sq)) {
                break;
            }
        }
    }

    return attacks;
}

uint64_t queen_moves(uint64_t occupancy, Square square) {
    return rook_moves(occupancy, square) | bishop_moves(occupancy, square);
}