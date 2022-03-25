#ifndef CHESS_GAME_PIECES_MOVE_H_
#define CHESS_GAME_PIECES_MOVE_H_

#include <iostream>

#include "examples/chess/chess-engine/Cell.h"

struct Move {
    Move(Cell src, Cell dst, double score);

    Cell source;
    Cell destination;
    double score;

    bool operator==(const Move &other) const;
    bool operator!=(const Move &other) const;

    struct HashFunction {
        size_t operator()(const Move &move) const {
            size_t srcHash = Cell::HashFunction()(move.source);
            size_t dstHash = Cell::HashFunction()(move.destination) << 16;

            return srcHash ^ dstHash;
        }
    };

    static const Move UNDEFINED;

    friend std::ostream& operator<<(std::ostream &os, const Move &move);
};

#endif /* CHESS_GAME_PIECES_MOVE_H_ */
