/*
 * PieceSelectionManager.cpp
 *
 *  Created on: Jan 12, 2022
 *      Author: ubuntu
 */

#include "PieceSelectionManager.h"
#include "chess-game/board/Board.h"

PieceSelectionManager::PieceSelectionManager(Board& board): _board(board) {
}

void PieceSelectionManager::clearSelection() {
	clickedPoint = Point::UNDEFINED;
	clickedBoardCell = Cell::UNDEFINED;
	selectedPiece = nullptr;
}

ChessState PieceSelectionManager::selectPiece(Point clickedPoint) {
	if (_board.isBoardPosition(clickedPoint)) {
		clickedBoardCell = _board.getCell(clickedPoint);
		bool isEmptyCell = _board.isEmptyCell(clickedBoardCell);

		if (!isEmptyCell) {
			Piece* pieceOnCell = _board.getPieceOnPosition(clickedBoardCell);

			if (pieceOnCell->side == Side::White) {
				std::cout << "Is the cell " << clickedBoardCell << " empty " << isEmptyCell << " and piece is " << *pieceOnCell << std::endl;

				selectedPiece = pieceOnCell;
				return ChessState::HUMAN_PIECE_SELECTED;
			}
		}
	}

	return ChessState::HUMAN_SELECT_PIECE;
}

bool PieceSelectionManager::isSidePieceSelected(Point point, Side side) {
	if (_board.isBoardPosition(point)) {
		Piece* selectedPiece = _board.getPieceOnPosition(_board.getCell(point));

		if (selectedPiece == nullptr) {
			return false;
		}

		if (selectedPiece->side == side) {
			return true;
		}
	}

	return false;
}