#pragma once

#include "Queen.h"

//this function checks if the queen can move all the directions,
//straight or diagonally
bool Queen::validMove(const Pos currPos, const Pos newPos) {
    return (abs(currPos.row - newPos.row) == abs(currPos.col - newPos.col) ||
        currPos.row == newPos.row || currPos.col == newPos.col);
}

//initiate white pieces
bool Queen::m_createWhite = Factory<PieceEntity>::reg('Q', []() -> std::unique_ptr<PieceEntity> {
    return std::make_unique<Queen>(WHITE);
    });
//initiate black pieces
bool Queen::m_createBlack = Factory<PieceEntity>::reg('q', []() -> std::unique_ptr<PieceEntity> {
    return std::make_unique<Queen>(BLACK);
    });