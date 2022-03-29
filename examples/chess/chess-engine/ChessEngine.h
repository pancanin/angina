#ifndef EXAMPLES_CHESS_CHESS_ENGINE_CHESSENGINE_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_CHESSENGINE_H_

#include <unordered_map>
#include <vector>

#include "examples/chess/chess-engine/Side.h"
#include "examples/chess/chess-engine/Cell.h"
#include "examples/chess/chess-engine/PlayerType.h"
#include "examples/chess/chess-engine/ChessState.h"
#include "examples/chess/chess-engine/ChessMoveLog.h"

struct ChessMoveManager;
struct ChessBoard;
struct Piece;

class ChessEngine {
public:
	ChessEngine(ChessBoard&, ChessMoveManager&, ChessMoveLog &moveLog,
			PlayerType whitePType = PlayerType::HUMAN, PlayerType blackPType =
					PlayerType::HUMAN);
	/*
	 * Used for human players.
	 * Selects a piece on the given cell. Returns whether the piece is selected.
	 */
	bool selectCell(const Cell&);

	/**
	 * Used for human players.
	 * Based on the previously selected piece, tries to make a move. Returns whether move was done.
	 */
	bool movePiece(const Cell&);

	/*
	 * Makes a computer move based on ChessMoveManager AI logic.
	 * Returns whether there are moves available. If none, it means that computer is in check or tie.
	 */
	bool makeComputerMove();

	/*
	 * Sets whether side is human/computer.
	 */
	void setPlayerType(Side, PlayerType);

	bool isCellSelected() const;

	ChessState getState() const;

private:
	ChessMoveManager &moveManager;
	ChessBoard &board;
	ChessMoveLog &log;
	Cell selectedCell;
	ChessState state;
	Side currentSide;
	PlayerType whitePlayerType;
	PlayerType blackPlayerType;
	std::unordered_map<Side, PlayerType> sideToPlayerType;

	/*
	 * Toggles between white/black.
	 */
	Side switchSide();

	/*
	 * Changes the state of the state machine.
	 */
	ChessState setState(ChessState);

	/*
	 * Returns whether the piece user is trying to select is of the side (black/white) that is currently on the move.
	 */
	bool isSelectedPieceOnTurn(const Piece&) const;

	/*
	 * Based on the current state and the type of white and black player, returns the next state;
	 */
	ChessState getNextState();

	void resetSelection();

	Side getEnemySide() const;

	/**
	 * Performs the move on a temporary board and checks whether the move is valid and the king is in check.
	 */
	bool isMoveAllowed(const Cell&, const Cell&) const;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_CHESSENGINE_H_ */
