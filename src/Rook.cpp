#pragma once

#include "Rook.h"

//this function checks if the rook can move straight (plus sign).
bool Rook::validMove(const Pos currPos, const Pos newPos) {
	return (currPos.row == newPos.row || currPos.col == newPos.col);
}

//initiate white pieces
bool Rook::m_registerWhite =Factory<PieceEntity>::reg('R', []() -> std::unique_ptr<PieceEntity> {
    return std::make_unique<Rook>(WHITE);
    });

//initiate black pieces
bool Rook::m_registerBlack = Factory<PieceEntity>::reg('r', []() -> std::unique_ptr<PieceEntity> {
    return std::make_unique<Rook>(BLACK);
    });