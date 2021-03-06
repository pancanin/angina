#ifndef EXAMPLES_CHESS_CHESSGAME_H_
#define EXAMPLES_CHESS_CHESSGAME_H_

#include <utility>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>

#include "engine/Engine.h"

#include "renderer/primitives/Dimensions.h"

#include "examples/chess/chess-engine/Piece.h"
#include "engine/primitives/cell/Cell.h"
#include "examples/chess/chess-engine/PlayerType.h"

struct Widget;
struct Object;
struct ChessBoard;
struct ChessEngine;
struct ChessMoveLog;
struct BoardBoundsPieceMoveGenerator;
struct FriendlyFireExcludedMoveGenerator;
struct ChessMoveManager;
struct TextStack;
struct MoveLogWidget;
struct Move;

typedef std::unordered_map<Cell, Object*, Cell::HashFunction> CellToObjectLookup;
typedef std::unordered_map<Cell, int32_t, Cell::HashFunction> CellToObjectId;
typedef std::unordered_map<Piece, std::string, Piece::HashFunction> PieceToResourcePath;

class ChessGame: public Engine {
public:
	ChessGame();
	~ChessGame();

	void init();
	void update();
	void handleLeftMouseClick(Point p);
	void handleBtnClick(int32_t idx);
private:
	ChessBoard *board = nullptr;
	BoardBoundsPieceMoveGenerator *baseMoveGen = nullptr;
	FriendlyFireExcludedMoveGenerator *moveGen = nullptr;
	ChessMoveManager *moveManager = nullptr;
	ChessEngine *engine = nullptr;
	ChessMoveLog *log = nullptr;
	MoveLogWidget *logTextWidget = nullptr;

	CellToObjectLookup cellObject;
	PieceToResourcePath pieceToResource;
	CellToObjectId cellToObjectId;
	PlayerType whitePlayerType;
	PlayerType blackPlayerType;
	bool loadingFromSave;

	std::vector<int32_t> possibleMoveCellsIds;

	Widget* buildLandingPage();

	Widget* buildChessPage();

	void startChessGame();

	/**
	 * Event handlers
	 */
	void handleStartGameButton();
	void handleQuitGameButton();
	void onChessWidgetDestroy();
	void handleHumanVSComputerButton();
	void handleComputerVSComputerButton();
	void handleMoveLog(const Move&);
	void handleSaveGameButton();
	void handleContinueGameButton();

	/*
	 * For every piece in the chess engine, create a drawable object. Keep a mapping between the two.
	 */
	void createPieceObjects();

	void pieceMovedCallback(const Cell &source, const Cell &destination);

	void initialiseChessClasses();

	void fillPossibleMoves(const Cell&);
	void clearPossibleMoves();
};

#endif /* EXAMPLES_CHESS_CHESSGAME_H_ */
