#include "LifeCore.h"

#include <stdexcept>

LifeCore::LifeCore(int numRows, int numCols)
    : rows(numRows > 0 ? numRows : throw std::logic_error("Ha")),
      cols(numCols),
      cells(rows * cols, false)
{ }

void LifeCore::updateCells()
{
    std::vector<bool> newCells(rows * cols, false);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
        {
            int numNeighs = numNeighbors(i,j);
            if (numNeighs == 2 && cells[i*cols + j])
                newCells[i*cols + j] = true;
            else if (numNeighs == 3)
                newCells[i*cols + j] = true;
        }

    cells = std::move(newCells);
}

int LifeCore::numNeighbors(int i, int j) const
{
    int num = 0;
    num += getCellState(i-1,j-1);
    num += getCellState(i-1,j);
    num += getCellState(i-1,j+1);
    num += getCellState(i,j-1);
    num += getCellState(i,j+1);
    num += getCellState(i+1,j-1);
    num += getCellState(i+1,j);
    num += getCellState(i+1,j+1);
    return num;
}
