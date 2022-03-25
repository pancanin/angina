#include "ChessEngine.h"

#include "examples/chess/chess-engine/ChessMoveManager.h"

ChessEngine::ChessEngine(ChessBoard &chessBoard, ChessMoveManager &moveMng,
        PlayerType whitePType, PlayerType blackPType) :
        moveManager(moveMng), board(chessBoard), selectedCell(Cell::UNDEFINED), state(
                ChessState::NO_OP), currentSide(Side::WHITE), whitePlayerType(
                whitePType), blackPlayerType(blackPType) {

    if (whitePlayerType == PlayerType::HUMAN) {
        state = ChessState::HUMAN_SELECT_PIECE;
    } else {
        state = ChessState::COMPUTER_MOVE;
    }

    sideToPlayerType[Side::WHITE] = whitePlayerType;
    sideToPlayerType[Side::BLACK] = blackPlayerType;
}

bool ChessEngine::selectCell(const Cell &cell) {
    if (state != ChessState::HUMAN_SELECT_PIECE || board.isEmptyCell(cell)) {
        return false;
    }

    Piece piece = board.getPieceOnCell(cell);

    if (!isSelectedPieceOnTurn(piece)) {
        return false;
    }

    selectedCell = cell;
    setState(ChessState::HUMAN_PIECE_SELECTED);

    return true;
}

bool ChessEngine::movePiece(const Cell &destination) {
    if (state != ChessState::HUMAN_PIECE_SELECTED) {
        return false;
    }

    bool moveOK = moveManager.movePiece(selectedCell, destination);

    bool isChecked = isKingAttacked();

    if (isChecked) {
        moveManager.movePiece(destination, selectedCell, true);
    }

    moveOK = moveOK && !isChecked;

    if (moveOK) {
        switchSide();
        setState(getNextState());
    } else {
        setState(ChessState::HUMAN_SELECT_PIECE);
    }

    resetSelection();

    return moveOK;
}

bool ChessEngine::isKingAttacked() {
    std::vector<Move> allEnemyMoves = moveManager.calculateAllAvailableMoves(
            getEnemySide());

    // From the 'check' logic we can safely say that we will always have a king piece on the board.
    Cell kingPosition = board.getPiecePosition(
            Piece { Rank::KING, currentSide });

    for (Move &m : allEnemyMoves) {
        if (m.destination == kingPosition) {
            return true;
        }
    }

    return false;
}

// TODO: Improve this once we get to AI
bool ChessEngine::makeComputerMove() {
    std::vector<Move> aiMoves = moveManager.getAIMoves(currentSide);

    for (Move &move : aiMoves) {
        std::cout << "The AI move is " << move << std::endl;

        moveManager.movePiece(move.source, move.destination);

        bool isChecked = isKingAttacked();

        if (isChecked) {
            // TODO: This part has a big fat bug. If there was a capture, we do not revert it here...
            // It would have been smart to use some CQRS type of pattern or command pattern with undo
            // so we can easily revert back the board.
            moveManager.movePiece(move.destination, move.source, true);
        } else {
            resetSelection();
            switchSide();
            setState(getNextState());

            return true;
        }
    }

    return false;
}

bool ChessEngine::isSelectedPieceOnTurn(const Piece &piece) const {
    return piece.side == currentSide;
}

ChessState ChessEngine::getNextState() {
    PlayerType nextPlayerType = sideToPlayerType[currentSide];

    if (nextPlayerType == PlayerType::COMPUTER) {
        return ChessState::COMPUTER_MOVE;
    } else {
        return ChessState::HUMAN_SELECT_PIECE;
    }
}

bool ChessEngine::isCellSelected() const {
    return selectedCell != Cell::UNDEFINED;
}

Side ChessEngine::switchSide() {
    Side cs = getEnemySide();
    currentSide = cs;
    return cs;
}

ChessState ChessEngine::setState(ChessState newState) {
    return state = newState;
}

ChessState ChessEngine::getState() const {
    return state;
}

void ChessEngine::resetSelection() {
    selectedCell = Cell::UNDEFINED;
}

Side ChessEngine::getEnemySide() const {
    return (currentSide == Side::WHITE) ? Side::BLACK : Side::WHITE;
}
