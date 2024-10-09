#include <cstdint>
#include <iostream>
#include "ChessBoard.h"


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

ChessBoard::ChessBoard() {
    // Inizializza tutte le bitboard a 0
    whitePawns = whiteKnights = whiteBishops = whiteRooks = whiteQueens = whiteKing = 0ULL;
    blackPawns = blackKnights = blackBishops = blackRooks = blackQueens = blackKing = 0ULL;

    // Posiziona i pezzi nella posizione iniziale
    initialize();
}

// Funzione per inizializzare la scacchiera nella posizione di partenza
void ChessBoard::initialize() {
    // Inizializza i pedoni
    whitePawns = 0x000000000000FF00ULL;
    blackPawns = 0x00FF000000000000ULL;

    // Inizializza i cavalli
    whiteKnights = 0x0000000000000042ULL;
    blackKnights = 0x4200000000000000ULL;

    // Inizializza gli alfieri
    whiteBishops = 0x0000000000000024ULL;
    blackBishops = 0x2400000000000000ULL;

    // Inizializza le torri
    whiteRooks = 0x0000000000000081ULL;
    blackRooks = 0x8100000000000000ULL;

    // Inizializza le regine
    whiteQueens = 0x0000000000000008ULL;
    blackQueens = 0x0800000000000000ULL;

    // Inizializza i re
    whiteKing = 0x0000000000000010ULL;
    blackKing = 0x1000000000000000ULL;

    // Iniazializza le board
    whiteBoard = whitePawns | whiteBishops | whiteKnights | whiteRooks | whiteQueens | whiteKing;
    blackBoard = blackPawns | blackBishops | blackKnights | blackRooks | blackQueens | blackKing;

    orBoard = whiteBoard | blackBoard;
}

//UTILS

// Funzione per posizionare un pezzo su una bitboard
void ChessBoard::setPiece(uint64_t& bitboard, int square) {
    bitboard |= (1ULL << square);  // Imposta il bit corrispondente
}

// Funzione per rimuovere un pezzo da una bitboard
void ChessBoard::removePiece(uint64_t& bitboard, int square) {
    bitboard &= ~(1ULL << square);  // Resetta il bit corrispondente
}

// Funzione per verificare se una casella è occupata su una bitboard
bool ChessBoard::isOccupied(uint64_t bitboard, int square)  {
    return bitboard & (1ULL << square);  // Controlla se il bit è 1
}


//STAMPA

// Funzione per stampare una singola bitboard in formato leggibile
void ChessBoard::printBitboard(uint64_t bitboard)  {
    for (int rank = 7; rank >= 0; --rank) {
        for (int file = 0; file < 8; ++file) {
            int square = rank * 8 + file;
            std::cout << (isOccupied(bitboard, square) ? "1 " : ". ");
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// Funzione per stampare tutte le bitboard
void ChessBoard::printAll()  {
    std::cout << "White Pawns:\n";
    printBitboard(whitePawns);
    std::cout << "Black Pawns:\n";
    printBitboard(blackPawns);

    std::cout << "White Knights:\n";
    printBitboard(whiteKnights);
    std::cout << "Black Knights:\n";
    printBitboard(blackKnights);

    std::cout << "White Bishops:\n";
    printBitboard(whiteBishops);
    std::cout << "Black Bishops:\n";
    printBitboard(blackBishops);

    std::cout << "White Rooks:\n";
    printBitboard(whiteRooks);
    std::cout << "Black Rooks:\n";
    printBitboard(blackRooks);

    std::cout << "White Queens:\n";
    printBitboard(whiteQueens);
    std::cout << "Black Queens:\n";
    printBitboard(blackQueens);

    std::cout << "White King:\n";
    printBitboard(whiteKing);
    std::cout << "Black King:\n";
    printBitboard(blackKing);
}