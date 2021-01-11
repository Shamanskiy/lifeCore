#include "LifeCore.h"
#include "gtest/gtest.h"

TEST(LifeCore, flipNormal)
{
    LifeCore core(2,2);
    core.flipCellState(0,0);
    ASSERT_TRUE(core.getCellState(0,0));
}

TEST(LifeCore, flipNegativeIndexX)
{
    LifeCore core(2,2);
    core.flipCellState(-2,0);
    ASSERT_TRUE(core.getCellState(0,0));
}

TEST(LifeCore, flipNegativeIndexY)
{
    LifeCore core(2,2);
    core.flipCellState(0,-2);
    ASSERT_TRUE(core.getCellState(0,0));
}

TEST(LifeCore, flipFailingTest)
{
    LifeCore core(2,2);
    //core.flipCellState(-2,0);
    ASSERT_TRUE(!core.getCellState(0,0));
}
