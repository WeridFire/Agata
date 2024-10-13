#include "queens.h"
#include "rooks.h"
#include "bishops.h"

uint64_t getQueenAttackMask(int sq) {
	return getBishopAttackMask(sq) | getRookAttackMask(sq);
}