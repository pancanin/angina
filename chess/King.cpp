//
// Created by ubuntu on 11/25/21.
//

#include "King.h"

King::King(int32_t _col, int32_t _row, Side _side, Image *_image): Piece(_col, _row, Rank::KING, _side, _image) {

}

King::~King() {

}

std::vector<Cell> King::calculateMoves(std::vector<Piece*> boardPieces) {
    std::vector<Cell> moves;

    moves.push_back({ piecePos.col, piecePos.row - 1 });
	moves.push_back({ piecePos.col + 1, piecePos.row - 1 });
	moves.push_back({ piecePos.col + 1, piecePos.row });
	moves.push_back({ piecePos.col + 1, piecePos.row + 1 });
	moves.push_back({ piecePos.col, piecePos.row + 1 });
	moves.push_back({ piecePos.col - 1, piecePos.row + 1 });
	moves.push_back({ piecePos.col - 1, piecePos.row });
	moves.push_back({ piecePos.col - 1, piecePos.row - 1 });

	return moves;
}
