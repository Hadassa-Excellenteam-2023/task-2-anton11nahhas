#pragma once

#include "Bishop.h"

//this function checks if the bishop can only move diagonally.
bool Bishop::validMove(const Pos currPos, const Pos newPos) {
    return abs(currPos.row - newPos.row) == abs(currPos.col - newPos.col);
}

//initiate white pieces
bool Bishop::m_createWhite = Factory<PieceEntity>::reg('B', []() -> std::unique_ptr<PieceEntity> {
    return std::make_unique<Bishop>(WHITE);
    });
//initiate black pieces
bool Bishop::m_createBlack = Factory<PieceEntity>::reg('b', []() -> std::unique_ptr<PieceEntity> {
    return std::make_unique<Bishop>(BLACK);
    });