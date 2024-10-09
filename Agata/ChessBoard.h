#pragma once
#include <cstdint>

class ChessBoard {
public:
    // Bitboard per i pezzi bianchi
    uint64_t whitePawns;
    uint64_t whiteKnights;
    uint64_t whiteBishops;
    uint64_t whiteRooks;
    uint64_t whiteQueens;
    uint64_t whiteKing;
    uint64_t whiteBoard;

    // Bitboard per i pezzi neri
    uint64_t blackPawns;
    uint64_t blackKnights;
    uint64_t blackBishops;
    uint64_t blackRooks;
    uint64_t blackQueens;
    uint64_t blackKing;
    uint64_t blackBoard;

    // OrBoard che contiene tutto
    uint64_t orBoard;

    // Costruttore
    ChessBoard();

    // Funzione per inizializzare la scacchiera nella posizione di partenza
    void initialize();

    // Funzione per posizionare un pezzo su una bitboard
    void setPiece(uint64_t& bitboard, int square);

    // Funzione per rimuovere un pezzo da una bitboard
    void removePiece(uint64_t& bitboard, int square);

    // Funzione per verificare se una casella è occupata su una bitboard
    bool isOccupied(uint64_t bitboard, int square);

    // Funzione per stampare una singola bitboard in formato leggibile
    void printBitboard(uint64_t bitboard);

    // Funzione per stampare tutte le bitboard
    void printAll();
};