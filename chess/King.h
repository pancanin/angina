//
// Created by ubuntu on 11/25/21.
//

#ifndef ANGINA_KING_H
#define ANGINA_KING_H


#include "Piece.h"

class King : public Piece {
public:
    King(int32_t _col, int32_t _row, Side _side, Image* _image);

    ~King();

    std::vector<Cell> calculateMoves(std::vector<Piece*> boardPieces);
};


#endif //ANGINA_KING_H
