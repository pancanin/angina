/*
 * AI.h
 *
 *  Created on: Jan 26, 2022
 *      Author: ubuntu
 */

#ifndef CHESS_GAME_AI_AI_H_
#define CHESS_GAME_AI_AI_H_

#include "chess-game/pieces/Side.h"
#include "chess-game/pieces/Move.h"
#include "chess-game/ai/ScoredMove.h"

#include "chess-game/utils/VectorShuffler.h"

struct Board;
struct ValidMovesGenerator;
struct Piece;

class AI {
public:
	AI(const Board& board, const ValidMovesGenerator& movesGen);

	ScoredMove findBestMove(Side side) const;
private:
	const Board& board;
	const ValidMovesGenerator& movesGenerator;
	VectorShuffler shuffler;

	double scoreMove(Piece* piece, Cell move) const;
};

#endif /* CHESS_GAME_AI_AI_H_ */