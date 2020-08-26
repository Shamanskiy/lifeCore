#include "LifeCore.h"

#include <iostream>

LifeCore::LifeCore(int numRows, int numCols)
    : rows(numRows),
      cols(numCols),
      cells(rows * cols, false)
{
    std::cout << cells.size() << std::endl;
}

bool LifeCore::getCellState(int i, int j) const
{
    return cells[i*cols + j];
}

void LifeCore::flipCellState(int i, int j)
{
    cells[i*cols + j] = !cells[i*cols + j];
}

void LifeCore::updateCells()
{

}
