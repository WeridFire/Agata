#pragma once
#include <cstdint>

// COSTANTI
const uint64_t notAFile = 0xfefefefefefefefe; // ~0x0101010101010101
const uint64_t notHFile = 0x7f7f7f7f7f7f7f7f; // ~0x8080808080808080

// FUNZIONI

// General shift
uint64_t genShift(uint64_t x, int s);

// Set di funzioni di spostamento bit all'interno della scacchiera
uint64_t soutOne(uint64_t b);    // Sposta verso il basso (sud)
uint64_t nortOne(uint64_t b);    // Sposta verso l'alto (nord)
uint64_t eastOne(uint64_t b);    // Sposta a est
uint64_t noEaOne(uint64_t b);    // Sposta nord-est
uint64_t soEaOne(uint64_t b);    // Sposta sud-est
uint64_t westOne(uint64_t b);    // Sposta a ovest
uint64_t soWeOne(uint64_t b);    // Sposta sud-ovest
uint64_t noWeOne(uint64_t b);    // Sposta nord-ovest

// Flipping / Mirroring
uint64_t flipVertical(uint64_t x);
uint64_t mirrorHorizontal(uint64_t x);
uint64_t flipDiagA1H8(uint64_t x);
uint64_t flipDiagA8H1(uint64_t x);
uint64_t rotate90clockwise(uint64_t x);

//Bitscan
int bitScanForward(uint64_t bb);