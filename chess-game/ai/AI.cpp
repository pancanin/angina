/*
 * AI.cpp
 *
 *  Created on: Jan 26, 2022
 *      Author: ubuntu
 */

#include <vector>
#include <algorithm>

#include "AI.h"

#include "chess-game/board/Board.h"
#include "chess-game/pieces/ValidMovesGenerator.h"
#include "chess-game/pieces/PieceValue.h"
#include "chess-game/pieces/Piece.h"

AI::AI(const Board& boardIn, const ValidMovesGenerator& movesGenIn): board(boardIn), movesGenerator(movesGenIn) {}

ScoredMove AI::findBestMove(Side side) const {
	// 1. Get all the pieces of the computer
	std::vector<ScoredMove> allMovesScored;

	std::vector<Piece*> pieces = board.getPiecesOfSide(side);

	shuffler.shuffle<Piece*>(pieces);

	// 2. for each piece return all valid moves
	for (Piece* candidatePiece : pieces) {
		std::vector<Move> validMoves = movesGenerator.generateValidMoves(candidatePiece);

		for (Move& m : validMoves) {
			allMovesScored.push_back(ScoredMove{m.dst, candidatePiece, scoreMove(candidatePiece, m.dst)});
		}
	}

	// 4. sort the moves with the highest scoring ones first.
	std::sort(allMovesScored.begin(), allMovesScored.end(), ScoredMove::HighestScoreComparator());

	return *allMovesScored.begin();
}

double AI::scoreMove(Piece* piece, Cell move) const {
	double totalScore = 0.0;

	Piece* pieceOnDestinationCell = board.getPieceOnPosition(move);

	if (pieceOnDestinationCell != nullptr) {
		totalScore += PieceValue::getPieceValue(pieceOnDestinationCell->rank);
	}

	/**
	 * Not sure whether this should be part of the cost function.
	 */
	if (board.isAttacked(piece, movesGenerator)) {
		std::cout << "Yes, this piece is attacked" << std::endl;
		//totalScore -= PieceValue::getPieceValue(piece->rank);
	}

	if (board.isInBoardCenter(move)) {
		totalScore += 1;
	}

	return totalScore;
}