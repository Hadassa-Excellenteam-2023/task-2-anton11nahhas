#pragma once

#include <iostream>
#include <vector>
#include "PieceEntity.h"
#include "Factory.h"

using std::string;

//board class, initiates the board and handles the response of each movement.
class Board {
public:
	Board(const std::string board) { appendPieces(board); }
	int getResponse(const std::string&);

private:
	
	void appendPieces(std::string board);
	bool checkForCheck(const bool color);
	bool nextStep(const Pos& curPos, const Pos& newPos);

	bool m_whitesTurn = true;
	Pos m_kingPos;
	std::vector<std::vector<std::unique_ptr<PieceEntity>>> m_board;
};