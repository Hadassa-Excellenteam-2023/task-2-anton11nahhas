#pragma once

#include <iostream>
#include "PieceEntity.h"

//bishop class uses constructor of pieceEntity, has 2 members and a single function
class Bishop : public PieceEntity {
public:
	using PieceEntity::PieceEntity;
	bool validMove(const Pos currPos, const Pos newPos) override;

private:
	static bool m_createWhite;
	static bool m_createBlack;

};