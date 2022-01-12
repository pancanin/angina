/*
 * Cell.cpp
 *
 *  Created on: Jan 9, 2022
 *      Author: ubuntu
 */

#include "Cell.h"

Cell::Cell(int32_t _row, int32_t _col): row(_row), col(_col) {

}

bool Cell::operator==(const Cell& cell) const {
	return row == cell.row && col == cell.col;
}

bool Cell::operator!=(const Cell& cell) const {
	return !(*this == cell);
}

const Cell Cell::UNDEFINED(10000, 10000);
