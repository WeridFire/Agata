#pragma once
#include <cstdint>
#include "Square.h"

uint64_t bishop_moves(uint64_t occupancy, Square square);

uint64_t rook_moves(uint64_t occupancy, Square square);

uint64_t queen_moves(uint64_t occupancy, Square square);
