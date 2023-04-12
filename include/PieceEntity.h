#pragma once

#include <iostream>
#include <string>
#include "macros.h"
#include "Factory.h"


//piece base class all pieces inherit from it and it is abstract
class PieceEntity {
public:

	PieceEntity(bool color) : m_color(color) {};
	virtual ~PieceEntity() = default;
	virtual bool validMove(const Pos currPos, const Pos newPos) = 0;

	bool getColor() const { return m_color; }
private:
	bool m_color = false;
};