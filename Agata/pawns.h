#pragma once
#include <cstdint>

//Filling
uint64_t nortFill(uint64_t gen);
uint64_t soutFill(uint64_t gen);
uint64_t fileFill(uint64_t gen);

// WHITE PUSH
uint64_t wSinglePushTargets(uint64_t wpawns, uint64_t empty);
uint64_t wDblPushTargets(uint64_t wpawns, uint64_t empty);

// BLACK PUSH
uint64_t bSinglePushTargets(uint64_t bpawns, uint64_t empty);
uint64_t bDoublePushTargets(uint64_t bpawns, uint64_t empty);

// WHITE ATTACKS
uint64_t wPawnEastAttacks(uint64_t wpawns);
uint64_t wPawnWestAttacks(uint64_t wpawns);
uint64_t wPawnAnyAttacks(uint64_t wpawns);
uint64_t wPawnDblAttacks(uint64_t wpawns);
uint64_t wPawnSingleAttacks(uint64_t wpawns);

// BLACK ATTACKS
uint64_t bPawnEastAttacks(uint64_t bpawns);
uint64_t bPawnWestAttacks(uint64_t bpawns);
uint64_t bPawnAnyAttacks(uint64_t bpawns);
uint64_t bPawnDblAttacks(uint64_t bpawns);
uint64_t bPawnSingleAttacks(uint64_t bpawns);