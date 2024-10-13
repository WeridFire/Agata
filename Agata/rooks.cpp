#include "rooks.h"
#include <cstdint>

uint64_t rankMask(int sq) {
    return 0xffULL << (sq & 56);
}
uint64_t fileMask(int sq) {
    return 0x0101010101010101ULL << (sq & 7);
}

uint64_t getRookAttackMask(int sq) {
    return rankMask(sq) | fileMask(sq);
}