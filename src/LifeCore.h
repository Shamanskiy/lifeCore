#pragma once

#include <vector>

// LifeCore contains a bool array representing a game field
// and implements logic for the game state evolution
class LifeCore
{
private:
    // size of the game field
    int rows, cols;
    // a rows x cols array of Life "cells"
    std::vector<bool> cells;

public:
    // ctor creates a game field of size numRows x numCols and
    // initializes all cells in the array with False
    explicit LifeCore(int numRows = 10, int numCols = 10);

    // rule of five: support copying and moving, default versions are OK
    ~LifeCore() = default;
    LifeCore(const LifeCore&) = default;
    LifeCore& operator=(const LifeCore&) = default;
    LifeCore(LifeCore&&) = default;
    LifeCore& operator=(LifeCore&&) = default;

    // get number of rows in the game field
    inline int numRows() const { return rows; }
    // get number of columnss in the game field
    inline int numCols() const { return cols; }

    // get state of cell at row i and column j; if an index does not belong to the interval [0,size-1], modulus is applied
    // ((A % B) + B) % B computes positive modulo also for negative numbers
    inline bool getCellState(int i, int j) const
    {
        return cells[(((i%rows)+rows)%rows) * cols + (j % cols + cols)%cols];
    }
    // flip cell state from dead to alive (if dead) or from alive to dead (if alive)
    inline void flipCellState(int i, int j)
    {
        int modI = (i % rows + rows) % rows;
        int modJ = (j % cols + cols) % cols;
        cells[modI * cols + modJ] = !cells[modI * cols + modJ % cols];
    }

    // compute next state of the game;
    // uses the most basic algorithm: to be improved
    void updateCells();

private:
    // computes number of alive neighbors for a given cell; uses periodic boundary
    int numNeighbors(int i, int j) const;
};
