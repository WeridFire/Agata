#include <cstdint>

//COSTANTI
const uint64_t notAFile = 0xfefefefefefefefe; // ~0x0101010101010101
const uint64_t notHFile = 0x7f7f7f7f7f7f7f7f; // ~0x8080808080808080
static const int index64[64] = {
        0, 1, 2, 7, 3, 13, 8, 19,
        4, 25, 14, 28, 9, 34, 20, 40,
        5, 17, 26, 38, 15, 46, 29, 48,
        10, 31, 35, 54, 21, 50, 41, 57,
        63, 6, 12, 18, 24, 27, 33, 39,
        16, 37, 45, 47, 30, 53, 49, 56,
        62, 11, 23, 32, 36, 44, 52, 55,
        61, 22, 43, 51, 60, 42, 59, 58
};


//FUNZIONI

//General shift
uint64_t genShift(uint64_t x, int s) {
	return (s > 0) ? (x << s) : (x >> -s);
}

//Set di funzioni di spostamento bit all'interno della scacchiera
uint64_t soutOne(uint64_t b) { return  b >> 8; }			  // Sposta verso il basso (sud)
uint64_t nortOne(uint64_t b) { return  b << 8; }			  // Sposta verso l'alto (nord)
uint64_t eastOne(uint64_t b) { return (b << 1) & notAFile; }  // Sposta a est
uint64_t noEaOne(uint64_t b) { return (b << 9) & notAFile; }  // Sposta nord-est
uint64_t soEaOne(uint64_t b) { return (b >> 7) & notAFile; }  // Sposta sud-est
uint64_t westOne(uint64_t b) { return (b >> 1) & notHFile; }  // Sposta a ovest
uint64_t soWeOne(uint64_t b) { return (b >> 9) & notHFile; }  // Sposta sud-ovest
uint64_t noWeOne(uint64_t b) { return (b << 7) & notHFile; }  // Sposta nord-ovest

//Flipping / Mirroring
/*
. 1 1 1 1 . . .   . 1 1 1 1 . . .   . 1 1 1 1 . . .   . 1 1 1 1 . . .
. 1 . . . 1 . .   . 1 . . . 1 . .   . 1 . . . 1 . .   . 1 . . . 1 . .
. 1 . . . 1 . .   . 1 . . . 1 . .   . 1 . . . 1 . .   . 1 . . . 1 . .
. 1 . . 1 . . .   . 1 . . 1 . . .   . 1 . . 1 . . .   . 1 . . 1 . . .
. 1 1 1 . . . .   . 1 1 1 . . . .   . 1 1 1 . . . .   . 1 1 1 . . . .
. 1 . 1 . . . .   . 1 . 1 . . . .   . 1 . 1 . . . .   . 1 . 1 . . . .
. 1 . . 1 . . .   . 1 . . 1 . . .   . 1 . . 1 . . .   . 1 . . 1 . . .
. 1 . . . 1 . .   . 1 . . . 1 . .   . 1 . . . 1 . .   . 1 . . . 1 . .
- |                  /               \
flipVertical     mirrorHorizontal  flipDiagA1H8      flipDiagA8H1
- |                /                   \
. 1 . . . 1 . .   . . . 1 1 1 1 .   . . . . . . . .   . . . . . . . .
. 1 . . 1 . . .   . . 1 . . . 1 .   . . . . . . . .   1 1 1 1 1 1 1 1
. 1 . 1 . . . .   . . 1 . . . 1 .   1 . . . . 1 1 .   1 . . . 1 . . .
. 1 1 1 . . . .   . . . 1 . . 1 .   . 1 . . 1 . . 1   1 . . . 1 1 . .
. 1 . . 1 . . .   . . . . 1 1 1 .   . . 1 1 . . . 1   1 . . 1 . . 1 .
. 1 . . . 1 . .   . . . . 1 . 1 .   . . . 1 . . . 1   . 1 1 . . . . 1
. 1 . . . 1 . .   . . . 1 . . 1 .   1 1 1 1 1 1 1 1   . . . . . . . .
. 1 1 1 1 . . .   . . 1 . . . 1 .   . . . . . . . .   . . . . . . . .
*/
uint64_t flipVertical(uint64_t x) {
    return  ((x << 56)) |
        ((x << 40) & 0x00ff000000000000ULL) |
        ((x << 24) & 0x0000ff0000000000ULL) |
        ((x << 8) & 0x000000ff00000000ULL) |
        ((x >> 8) & 0x00000000ff000000ULL) |
        ((x >> 24) & 0x0000000000ff0000ULL) |
        ((x >> 40) & 0x000000000000ff00ULL) |
        ((x >> 56));
}
uint64_t mirrorHorizontal(uint64_t x) {
    const uint64_t k1 = 0x5555555555555555ULL;
    const uint64_t k2 = 0x3333333333333333ULL;
    const uint64_t k4 = 0x0f0f0f0f0f0f0f0fULL;

    x = ((x >> 1) & k1) | ((x & k1) << 1);
    x = ((x >> 2) & k2) | ((x & k2) << 2);
    x = ((x >> 4) & k4) | ((x & k4) << 4);

    return x;
}
uint64_t flipDiagA1H8(uint64_t x) {
    uint64_t t;
    const uint64_t k1 = 0x5500550055005500ULL;
    const uint64_t k2 = 0x3333000033330000ULL;
    const uint64_t k4 = 0x0f0f0f0f00000000ULL;

    t = k4 & (x ^ (x << 28));
    x ^= t ^ (t >> 28);
    t = k2 & (x ^ (x << 14));
    x ^= t ^ (t >> 14);
    t = k1 & (x ^ (x << 7));
    x ^= t ^ (t >> 7);

    return x;
}
uint64_t flipDiagA8H1(uint64_t x) {
    uint64_t t;
    const uint64_t k1 = 0xaa00aa00aa00aa00ULL;
    const uint64_t k2 = 0xcccc0000cccc0000ULL;
    const uint64_t k4 = 0xf0f0f0f00f0f0f0fULL;

    t = x ^ (x << 36);
    x ^= k4 & (t ^ (x >> 36));
    t = k2 & (x ^ (x << 18));
    x ^= t ^ (t >> 18);
    t = k1 & (x ^ (x << 9));
    x ^= t ^ (t >> 9);

    return x;
}
uint64_t rotate90clockwise(uint64_t x) {
    return flipVertical(flipDiagA1H8(x));
}

//Bitscan
//ritorna indice primo bit settato ad uno di bb
int bitScanForward(uint64_t bb) {
    if (bb == 0) return -1; // Caso speciale per bb = 0
    uint64_t isolatedBit = bb & ~bb; // Isola il bit meno significativo impostato a 1
    uint64_t debruijn64 = 0x03f79d71b4cb0a89ULL;
    int index = index64[(isolatedBit * debruijn64) >> 58];
    return index;
}

//Masks
uint64_t getHigherMask(int sq) {
    return 0xFFFFFFFFFFFFFFFFULL << sq;
}
uint64_t getLowerMask(int sq) {
    return 0xFFFFFFFFFFFFFFFFULL >> (63-sq);
}