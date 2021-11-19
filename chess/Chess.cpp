/*
 * Chess.cpp
 *
 *  Created on: Nov 15, 2021
 *      Author: ubuntu
 */

#include "Chess.h"

void Chess::init() {
	std::vector<Texture*> textures = loadGameTextures(paths);
	SDL_Rect boardRect = {
			0, 0, 640, 640
	};
	SDL_Rect pieceRect = {

	};

	this->boardImage = new Image(*textures.at(0), boardRect);

	for (uint32_t pawnCounter = 0; pawnCounter < 8; pawnCounter++) {
		this->whitePieces.push_back(new Piece(pawnCounter, pawnCounter, 1, Rank::Pawn, Side::White));

		this->blackPieces.push_back(new Piece(-pawnCounter, pawnCounter, 6, Rank::Pawn, Side::Black));
	}
}

void Chess::draw() {
	this->renderer.clearRenderer();

	this->boardImage->draw(this->renderer);

	this->renderer.updateScreen();
	SDL_Delay(50);
}

void Chess::executeGameLogic() {

}

Image* Chess::getImageFromPiece(Piece* piece) {

}
