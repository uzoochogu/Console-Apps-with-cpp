/**
 * @file 8_Queens_problem.cpp
 * @author Uzo Ochogu (uzoochogu@yahoo.com)
 * @brief This program finds the possible ways that 8 Queens can be arranged on a chess board such thay no queen can attack another queen
 * @version 0.1
 * @date 2022-08-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <string>


class Board
{

};

/**
 * @brief Utility function for solve8Queens()
 * 
 * @param board the board to solve
 * @param column keeps track of the current column being solved for
 */
void solve8QueensUtil(Board& board, int column)
{
    if(column >= 8)
        std::cout << board.toString() << std::endl;
    else
    {
        //We need to place 1 queen in this column
        //for each possible place in this column
        for (int row = 0; row < 9; row++)
        {
            //choose
            board.place(row, column);

            //explore
            solve8QueensUtil(board, column + 1);

            //unchoose
            board.remove(row, column);
        }
    }    
}

/**
 * @brief Prints the boards that satisfy the possible ways that 8 Queens can be arranged on a chess board such thay no queen can attack another queen
 * 
 * @param board 
 */
void solve8Queens(Board& board)
{
    solve8QueensUtil(board, 0);
}


int main()
{


    return 0;
}
