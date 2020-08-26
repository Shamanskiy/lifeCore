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

    // get state of cell at row i and column j
    bool getCellState(int i, int j) const;
    // flip cell state from dead to alive (if dead) or from alive to dead (if alive)
    void flipCellState(int i, int j);

    // compute next state of the game
    void updateCells();
};
