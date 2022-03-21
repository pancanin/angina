#include "FriendlyFireExcludedMoveGenerator.h"

#include "examples/chess/chess-engine/ChessBoard.h"
#include "examples/chess/chess-engine/BoundsMoveGenerator.h"

FriendlyFireExcludedMoveGenerator::FriendlyFireExcludedMoveGenerator(
		ChessBoard& chessBoard,
		BoundsMoveGenerator& generator
): board(chessBoard), moveGen(generator) {}

CellUnorderedSet FriendlyFireExcludedMoveGenerator::generatePieceMoves(const Cell& pieceCell) const {
	CellUnorderedSet friendlyFireExcludedMoves;

	Piece piece = board.getPieceOnCell(pieceCell);

	CellUnorderedSet boundedMoves = moveGen.generatePieceMoves(piece, pieceCell);

	for (auto const& cell : boundedMoves) {
		if (board.isValidTarget(cell, piece.side)) {
			friendlyFireExcludedMoves.insert(cell);
		}
	}

	std::cout << "How many moves has the pawn " << friendlyFireExcludedMoves.size() << std::endl;

	return friendlyFireExcludedMoves;
}