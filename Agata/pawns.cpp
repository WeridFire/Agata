#include <cstdint>
#include "utility.h"


//Filling North or south
/*
white nortfill     black nortfill
1 1 1 . . 1 1 1     1 1 1 1 . 1 1 1
1 1 1 . . 1 1 1     1 1 1 1 . 1 1 1
1 1 1 . . 1 1 1     1 . 1 1 . . . 1
1 1 1 . . 1 1 1     . . . 1 . . . .
1 1 1 . . 1 1 1  ^  . . . . . . . .
. 1 1 . . . 1 1  |   . . . . . . . .
. 1 1 . . . 1 1  |   . . . . . . . .
. . . . . . . .  |   . . . . . . . .
               north
white pawns         black pawns
. . . . . . . .     . . . . . . . .
. . . . . . . .     . 1 . . . 1 1 .
. . . . . . . .     1 . 1 . . . . 1
. . . . . . . .     . . . 1 . . . .
1 . . . . 1 . .     . . . . . . . .
. . 1 . . . . .     . . . . . . . .
. 1 1 . . . 1 1     . . . . . . . .
. . . . . . . .     . . . . . . . .
               south
white soutfill      black soutfill
. . . . . . . .  |  . . . . . . . .
. . . . . . . .  |  . 1 . . . 1 1 .
. . . . . . . .  |  1 1 1 . . 1 1 1
. . . . . . . .  v  1 1 1 1 . 1 1 1
1 . . . . 1 . .     1 1 1 1 . 1 1 1
1 . 1 . . 1 . .     1 1 1 1 . 1 1 1
1 1 1 . . 1 1 1     1 1 1 1 . 1 1 1
1 1 1 . . 1 1 1     1 1 1 1 . 1 1 1


white filefill      black filefill
1 1 1 . . 1 1 1     1 1 1 1 . 1 1 1
1 1 1 . . 1 1 1     1 1 1 1 . 1 1 1
1 1 1 . . 1 1 1     1 1 1 1 . 1 1 1
1 1 1 . . 1 1 1     1 1 1 1 . 1 1 1
1 1 1 . . 1 1 1     1 1 1 1 . 1 1 1
1 1 1 . . 1 1 1     1 1 1 1 . 1 1 1
1 1 1 . . 1 1 1     1 1 1 1 . 1 1 1
1 1 1 . . 1 1 1     1 1 1 1 . 1 1 1
*/
uint64_t nortFill(uint64_t gen) {
    gen |= (gen << 8);
    gen |= (gen << 16);
    gen |= (gen << 32);
    return gen;
}
uint64_t soutFill(uint64_t gen) {
    gen |= (gen >> 8);
    gen |= (gen >> 16);
    gen |= (gen >> 32);
    return gen;
}
uint64_t fileFill(uint64_t gen) {
    return nortFill(gen) | soutFill(gen);
}

// WHITE PUSH
uint64_t wSinglePushTargets(uint64_t wpawns, uint64_t empty) {
    return nortOne(wpawns) & empty;
}
uint64_t wDblPushTargets(uint64_t wpawns, uint64_t empty) {
    const uint64_t rank4 = 0x00000000FF000000ULL;
    uint64_t singlePushs = wSinglePushTargets(wpawns, empty);
    return nortOne(singlePushs) & empty & rank4;
}

// BLACK PUSH
uint64_t bSinglePushTargets(uint64_t bpawns, uint64_t empty) {
    return soutOne(bpawns) & empty;
}
uint64_t bDoublePushTargets(uint64_t bpawns, uint64_t empty) {
    const uint64_t rank5 = 0x000000FF00000000ULL;
    uint64_t singlePushs = bSinglePushTargets(bpawns, empty);
    return soutOne(singlePushs) & empty & rank5;
}

// WHITE ATTACKS
uint64_t wPawnEastAttacks(uint64_t wpawns) {
    return noEaOne(wpawns);
}
uint64_t wPawnWestAttacks(uint64_t wpawns) {
    return noWeOne(wpawns);
}
uint64_t wPawnAnyAttacks(uint64_t wpawns) {
    return wPawnEastAttacks(wpawns) | wPawnWestAttacks(wpawns);
}
uint64_t wPawnDblAttacks(uint64_t wpawns) {
    return wPawnEastAttacks(wpawns) & wPawnWestAttacks(wpawns);
}
uint64_t wPawnSingleAttacks(uint64_t wpawns) {
    return wPawnEastAttacks(wpawns) ^ wPawnWestAttacks(wpawns);
}

// BLACK ATTACKS
uint64_t bPawnEastAttacks(uint64_t bpawns) {
    return soEaOne(bpawns);
}
uint64_t bPawnWestAttacks(uint64_t bpawns) {
    return soWeOne(bpawns);
}
uint64_t bPawnAnyAttacks(uint64_t bpawns) {
    return bPawnEastAttacks(bpawns) | wPawnWestAttacks(bpawns);
}
uint64_t bPawnDblAttacks(uint64_t bpawns) {
    return wPawnEastAttacks(bpawns) & wPawnWestAttacks(bpawns);
}
uint64_t bPawnSingleAttacks(uint64_t bpawns) {
    return wPawnEastAttacks(bpawns) ^ wPawnWestAttacks(bpawns);
}