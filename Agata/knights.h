#pragma once

const uint64_t notAFile = 0xFEFEFEFEFEFEFEFEULL;  // Maschera per evitare l'uscita dal file A (colonna più a sinistra)
const uint64_t notABFile = 0xFCFCFCFCFCFCFCFCULL;  // Maschera per evitare l'uscita dai file A e B
const uint64_t notHFile = 0x7F7F7F7F7F7F7F7FULL;  // Maschera per evitare l'uscita dal file H (colonna più a destra)
const uint64_t notGHFile = 0x3F3F3F3F3F3F3F3FULL;  // Maschera per evitare l'uscita dai file G e H

uint64_t noNoEa(uint64_t b);
uint64_t noEaEa(uint64_t b);
uint64_t soEaEa(uint64_t b);
uint64_t soSoEa(uint64_t b);
uint64_t noNoWe(uint64_t b);
uint64_t noWeWe(uint64_t b);
uint64_t soWeWe(uint64_t b);
uint64_t soSoWe(uint64_t b);
uint64_t getKnightMoves(uint64_t knights);