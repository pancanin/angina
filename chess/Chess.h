/*
 * Chess.h
 *
 *  Created on: Nov 15, 2021
 *      Author: ubuntu
 */

#ifndef CHESS_CHESS_H_
#define CHESS_CHESS_H_

#include "sdl/graphics/Engine.h"
#include "resources/Resources.h"
#include "Piece.h"

#include <cstdint>
#include <vector>
#include <string>
#include <map>

class Chess : public Engine {
public:
	void init();
	void executeGameLogic();
	void draw();

	Image* getImageFromPiece(Piece* piece);

	void handleUpArrowKey() {};
	void handleDownArrowKey() {};
	void handleLeftArrowKey() {};
	void handleRightArrowKey() {};
	void handleOtherKey() {};
private:
	Image* boardImage;
	std::vector<std::string> paths = {
		Resources::board,
		Resources::blackBishop,
		Resources::blackKing,
		Resources::blackKnight,
		Resources::blackPawn,
		Resources::blackQueen,
		Resources::blackRook,
		Resources::whiteBishop,
		Resources::whiteKing,
		Resources::whiteKnight,
		Resources::whitePawn,
		Resources::whiteQueen,
		Resources::whiteRook
	};
	uint32_t board[8][8];
	std::vector<Piece*> whitePieces;
	std::vector<Piece*> blackPieces;
	std::map<int32_t, Image*> pieceImages;
};


#endif /* CHESS_CHESS_H_ */
