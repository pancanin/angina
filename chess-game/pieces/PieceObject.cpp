#include "PieceObject.h"
#include "sdl/engine/object/Object.h"

PieceObject::PieceObject(Object& objectIn, Cell cellIn, Side sideIn, Rank rankIn): object(objectIn), cell(cellIn), side(sideIn), rank(rankIn), hasMoved(false) {}

void PieceObject::move(const Point point, const Cell dst) {
	object.move(point.x, point.y);
	cell = dst;
	hasMoved = true;
}

std::ostream& operator<<(std::ostream& os, const Piece& piece) {
	return os << "\tPosition: " << piece.cell << "\n\t Rank: " << piece.rank << "\n\t Side: " << piece.side;
}