#include "LifeCore.h"

#include <stdexcept>

LifeCore::LifeCore(int numRows, int numCols)
    : rows(numRows > 0 ? numRows : throw std::logic_error("Ha")),
      cols(numCols),
      cells(rows * cols, false)
{ }

void LifeCore::updateCells()
{
    flipCellState(0,0);
}
