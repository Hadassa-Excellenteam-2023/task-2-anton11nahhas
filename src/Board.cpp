#pragma once

#include "Board.h"
#include "King.h"

//this function initiates the board member it first initiates it to the board size
//filling it with 0's (using the resize function for vectors) and then loops through
//the board passed with it as a parameter and using factory design creates the objects
//as well as it fills the board member with the correct positioning of the pieces.
void Board::appendPieces(std::string board) {
	m_board.resize(8); 
	for (auto& row : m_board) {
		row.resize(8); 
	}

	for (int i = 0; i < board.size(); ++i) {
		int row = i / 8;
		int col = i % 8;
		m_board[row][col] = Factory<PieceEntity>::createPiece(board[i]);
	}
}

//this function receives the input from the user, and checks the validity of that
//input, in other words, if the move was legal or not, accordingly, it returns 
//the suitable response code
int Board::getResponse(const std::string& res) {
	//convers the input of letters and numbers to rows and cols suitable to our board
	Pos currPos = { res[0] - 'a', res[1] - '1' };
	Pos newPos = { res[2] - 'a', res[3] - '1' };

	//check if the curr position does not have a piece
	if (!m_board[currPos.row][currPos.col]) {
		return 11;
	}

	//check if the curr pos is occupied by the oponent
	if (m_board[currPos.row][currPos.col]->getColor() != m_whitesTurn) {
		return 12;
	}

	//check if the new pos has the same color of the curr player
	if (m_board[newPos.row][newPos.col] && m_board[currPos.row][currPos.col]->getColor() == m_board[newPos.row][newPos.col]->getColor()) {
		return 13;
	}

	//check if the move of that piece is valid or not
	if (!m_board[currPos.row][currPos.col]->validMove(currPos, newPos) || !nextStep(currPos, newPos)) {
		return 21;
	}

	//the move must be valid update the new position
	m_board[newPos.row][newPos.col] = move(m_board[currPos.row][currPos.col]);


	//check if the newposition caused a check on the player's king
	if (checkForCheck(m_whitesTurn)) {
		m_board[currPos.row][currPos.col] = move(m_board[newPos.row][newPos.col]);
		return 31;
	}

	//change turns
	bool turn = !m_whitesTurn; 
	m_whitesTurn = !m_whitesTurn;

	//check if a check is caused to the openents king
	if (checkForCheck(turn)) {
		return 41;
	}

	//a clean valid move
	return 42;


}

//this function receives the players turn color and check for a check, meaning
//if the openets king or the players king is on check, it do so by first finding the
//position of the king on the board, then check if any of the opposite color checks
//the king on that position. returns true if the king is on check and false otherwise.
bool Board::checkForCheck(const bool color) {
	
	for (int row = 0; row < 8; ++row) {
		for (int col = 0; col < 8; ++col) {
			if (m_board[row][col] != nullptr && m_board[row][col]->getColor() == WHITE &&
				typeid(*m_board[row][col]) == typeid(King)) {
				m_kingPos.row = row;
				m_kingPos.col = col;
			}
		}
	}

	for (int row = 0; row < 8; ++row) {
		for (int col = 0; col < 8; ++col) {
			if (m_board[row][col] != nullptr && m_board[row][col]->getColor() != WHITE) {
				Pos piecePos = { row, col };
				if (m_board[row][col]->validMove(piecePos, m_kingPos) && nextStep(piecePos, m_kingPos)) {
					return true;
				}
			}
		}
	}

	return false;
}

//this function receives the current position and the new position and checks
//the steps from the curr to the new position gradually, this is done to check
//if the path the piece is crossing is not blocked by another piece. returns 
//true if the path is clear and false otherwise
bool Board::nextStep(const Pos& curPos, const Pos& newPos) {
	int deltaRow = newPos.row - curPos.row;
	int deltaCol = newPos.col - curPos.col;

	//compute the direction the piece is going 
	int rowDir = (deltaRow == 0) ? 0 : deltaRow / abs(deltaRow);
	int colDir = (deltaCol == 0) ? 0 : deltaCol / abs(deltaCol);

	
	int checkRow = curPos.row + rowDir;
	int checkCol = curPos.col + colDir;
	//move gradually towards the new position
	while (checkRow != newPos.row || checkCol != newPos.col) {
		if (m_board[checkRow][checkCol] != nullptr) {//if the path is blocked on the way
			return false;//return false, path is blocked
		}
		checkRow += rowDir;
		checkCol += colDir;
	}

	return true;//otherwise return true
}