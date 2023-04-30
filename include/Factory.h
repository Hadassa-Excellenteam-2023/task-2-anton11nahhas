#pragma once

#include "macros.h"
#include <map>
#include <typeinfo>
#include <typeindex>
#include <memory>
#include <utility>

using std::unique_ptr;
using std::make_unique;

class PieceEntity;

//Factory class, declares a map where the keys are the name if the pieces and
//the values are the unique pointers made, in other words the piece objects.
//the factory creates and initiates all the pieces on the board
template<typename T>
class Factory {
public:
    using pieceObject = std::unique_ptr<T>(*)();

    static std::unique_ptr<T> createPiece(const char&);

    static bool reg(const char&, pieceObject);

private: 

    static auto& getMap() {
        static std::map<char, pieceObject> m_map;
        return m_map;
    }
};


//create piece function receives the piece name, finds the piece in the map
//and returns the value (the object of that piece).
template<typename T>
std::unique_ptr<T> Factory<T>::createPiece(const char& pieceName) {
    auto piece = Factory<T>::getMap().find(pieceName);
    if (piece == Factory<T>::getMap().end())
        return nullptr;
    return piece->second();
}

//a register function, receives the piece name and object and emplaces them
//onto the map 
template<typename T>
bool Factory<T>::reg(const char& pieceName, pieceObject piece) {
    Factory<T>::getMap().emplace(pieceName, piece);
    return true;
}