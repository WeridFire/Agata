#include "knights.h"
#include <cstdint>

//        noNoWe    noNoEa
//            +15  +17
//             |     |
//noWeWe  +6 __|     |__+10  noEaEa
//              \   /
//               >0<
//           __ /   \ __
//soWeWe -10   |     |   -6  soEaEa
//             |     |
//            -17  -15
//        soSoWe    soSoEa

const uint64_t notAFile = 0xFEFEFEFEFEFEFEFEULL;  // Maschera per evitare l'uscita dal file A (colonna più a sinistra)
const uint64_t notABFile = 0xFCFCFCFCFCFCFCFCULL;  // Maschera per evitare l'uscita dai file A e B
const uint64_t notHFile = 0x7F7F7F7F7F7F7F7FULL;  // Maschera per evitare l'uscita dal file H (colonna più a destra)
const uint64_t notGHFile = 0x3F3F3F3F3F3F3F3FULL;  // Maschera per evitare l'uscita dai file G e H

uint64_t noNoEa(uint64_t b) {
    return (b << 17) & notAFile;  // Movimento a nord-nord-est
}
uint64_t noEaEa(uint64_t b) {
    return (b << 10) & notABFile; // Movimento a nord-est-est
}
uint64_t soEaEa(uint64_t b) {
    return (b >> 6) & notABFile;  // Movimento a sud-est-est
}
uint64_t soSoEa(uint64_t b) {
    return (b >> 15) & notAFile;  // Movimento a sud-sud-est
}
uint64_t noNoWe(uint64_t b) {
    return (b << 15) & notHFile;  // Movimento a nord-nord-ovest
}
uint64_t noWeWe(uint64_t b) {
    return (b << 6) & notGHFile;  // Movimento a nord-ovest-ovest
}
uint64_t soWeWe(uint64_t b) {
    return (b >> 10) & notGHFile; // Movimento a sud-ovest-ovest
}
uint64_t soSoWe(uint64_t b) {
    return (b >> 17) & notHFile;  // Movimento a sud-sud-ovest
}

uint64_t getKnightMoves(uint64_t knights) {
    return noNoEa(knights) | noEaEa(knights) | soEaEa(knights) | soSoEa(knights) |
        noNoWe(knights) | noWeWe(knights) | soWeWe(knights) | soSoWe(knights);
}

