#include <iostream>
#include <array>
#include <bitset>
#include <vector>

class Solution
{
public:
    void solveSudoku(std::vector<std::vector<char>> &board) const noexcept
    {
        /*
        Note: input is guaranteed to be a valid board using only '1'-'9' and '.' with a uniquesolution.
        Solution should modify board, not return a new one.
        */




    }

};

//Utility function to print board
void print_board(std::vector<std::vector<char>> board)
{
    for(size_t row = 0; row < 9; ++row)
    {
        for(size_t column = 0; column < 9; ++column)
        {
            std::cout << board[row][column] << ", ";
        }
    }
} 

//Driver code with a test case
int main()
{
    std::array<char, 81> const flat_board = {'5', '3', '.', '.', '7', '.', '.', '.', '.',
                                             '6', '.', '.', '1', '9', '5', '.', '.', '.',
                                             '.', '9', '8', '.', '.', '.', '.', '6', '.',
                                             '8', '.', '.', '.', '6', '.', '.', '.', '3',
                                             '4', '.', '.', '8', '.', '3', '.', '.', '1',
                                             '7', '.', '.', '.', '2', '.', '.', '.', '6',
                                             '.', '6', '.', '.', '.', '.', '2', '8', '.',
                                             '.', '.', '.', '4', '1', '9', '.', '.', '5',
                                             '.', '.', '.', '.', '8', '.', '.', '7', '9',};

    std::array<char, 81> const flat_board = {'5', '3', '4', '6', '7', '8', '9', '1', '2',
                                             '6', '7', '2', '1', '9', '5', '3', '4', '8',
                                             '1', '9', '8', '3', '4', '2', '5', '6', '7',
                                             '8', '5', '9', '7', '6', '1', '4', '2', '3',
                                             '4', '2', '6', '8', '5', '3', '7', '9', '1',
                                             '7', '1', '3', '9', '2', '4', '8', '5', '6',
                                             '9', '6', '1', '5', '3', '7', '2', '8', '4',
                                             '2', '8', '7', '4', '1', '9', '6', '3', '5',
                                             '3', '4', '5', '2', '8', '6', '1', '7', '9',} ;                                                                                       

    return 0;
}