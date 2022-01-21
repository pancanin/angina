#ifndef CHESS_GAME_PIECES_PIECE_H_
#define CHESS_GAME_PIECES_PIECE_H_

#include <iostream>

#include "sdl/primitives/Point.h"

#include "chess-game/board/Cell.h"
#include "chess-game/pieces/Side.h"
#include "chess-game/pieces/Rank.h"

struct Object;

struct Piece {
	Piece(Object& object, Cell cell, Side side, Rank rank);

	Object& object;
	Cell cell;
	const Side side;
	const Rank rank;
	bool hasMoved;

	void move(const Point point, const Cell cell);

	friend std::ostream& operator<<(std::ostream& os, const Piece& piece);
};

#endif /* CHESS_GAME_PIECES_PIECE_H_ */
