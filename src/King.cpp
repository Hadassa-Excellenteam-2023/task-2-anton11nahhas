#pragma once

#include "King.h"

//this function checks if the king can move a ingle block per turn
bool King::validMove(const Pos currPos, const Pos newPos) {
	return abs(currPos.row - newPos.row) <= 1 && abs(currPos.col - newPos.col) <= 1;
}

//initiate white pieces
bool King::m_createWhite = Factory<PieceEntity>::reg('K', []() -> std::unique_ptr<PieceEntity> {
        return std::make_unique<King>(WHITE);
    });

//initiate black pieces
bool King::m_createBlack = Factory<PieceEntity>::reg('k', []() -> std::unique_ptr<PieceEntity> {
        return std::make_unique<King>(BLACK);
    });