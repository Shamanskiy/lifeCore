#include "LifeCore.h"

#include <iostream>
#include <chrono>
#include <thread>

// set the game state to Kok's galaxy
void createKoksGalaxy(LifeCore& lc)
{
    int rows = lc.numRows();
    int cols = lc.numCols();
    if (rows < 15 || cols < 15)
    {
        std::cout << "Game field is too small for Kok's galaxy\n";
        return;
    }

    int centerI = (rows-1)/2;
    int centerJ = (cols-1)/2;

    for (int i = 0; i < 6; ++i)
    {
        lc.flipCellState(centerI - 4 + i, centerJ - 4);
        lc.flipCellState(centerI - 4 + i, centerJ - 3);

        lc.flipCellState(centerI + 4 - i, centerJ + 4);
        lc.flipCellState(centerI + 4 - i, centerJ + 3);

        lc.flipCellState(centerI - 4, centerJ + 4 - i);
        lc.flipCellState(centerI - 3, centerJ + 4 - i);

        lc.flipCellState(centerI + 4, centerJ - 4 + i);
        lc.flipCellState(centerI + 3, centerJ - 4 + i);
    }
}

// draw a horizontal line in the terminal with a given width
void drawHorizontalBorder(int width)
{
    std::cout << " ";
    for (int i = 0; i < width; ++i)
        std::cout << "==";
    std::cout << "= \n";
}

// draw the current game field to the console
void drawField(const LifeCore& lc)
{
    // clear the terminal
    std::system("clear");

    // over title border
    drawHorizontalBorder(lc.numCols());

    // center the title
    int fieldWidth = lc.numCols() * 2 + 3;
    if (fieldWidth >= 21)
        for (int i = 0; i < (fieldWidth - 21)/2; ++i )
            std::cout << " ";
    std::cout << "Conway's Game of Life\n"; // 21 symbol

    // top field border
    drawHorizontalBorder(lc.numCols());

    // game field
    for (int i = 0; i < lc.numRows(); ++i)
    {
        // left boundary
        std::cout << "| ";
        // cells
        for (int j = 0; j < lc.numCols(); ++j)
            std::cout << (lc.getCellState(i,j) ? "x " : "  ");
        // right boundary
        std::cout << "|\n";
    }

    // bottom field border
    drawHorizontalBorder(lc.numCols());
}

int main(void)
{
    // create a 15x15 game field
    LifeCore lc(15,15);
    // create a Kok's galaxy in the center
    createKoksGalaxy(lc);

    // run the game loop until interrupted
    while(true)
    {
       drawField(lc);
       lc.updateCells();
       std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
    return 0;
}
