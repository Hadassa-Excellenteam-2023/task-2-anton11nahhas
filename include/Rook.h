#pragma once

#include <iostream>
#include "PieceEntity.h"


//rook class uses constructor of pieceEntity, has 2 members and a single function
class Rook : public PieceEntity {
public:
	using PieceEntity::PieceEntity;
	bool validMove(const Pos currPos, const Pos newPos) override;
private:
	static bool m_registerWhite;
	static bool m_registerBlack;

};