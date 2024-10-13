#include <cstdint>
#include "bishops.h"
/*
  noWe         nort         noEa
          +7    +8    +9
              \  |  /
  west    -1 <-  0 -> +1    east
              /  |  \
          -9    -8    -7
  soWe         sout         soEa
*/

uint64_t diagonalMask(int sq) {
    const uint64_t maindia = 0x8040201008040201ULL;
    int diag = (sq & 7) - (sq >> 3);
    return diag >= 0 ? maindia >> diag * 8 : maindia << -diag * 8;
}
uint64_t antiDiagMask(int sq) {
    const uint64_t maindia = 0x0102040810204080ULL;
    int diag = 7 - (sq & 7) - (sq >> 3);
    return diag >= 0 ? maindia >> diag * 8 : maindia << -diag * 8;
}

uint64_t getBishopAttackMask(int sq) {
    return diagonalMask(sq) | antiDiagMask(sq);
}
