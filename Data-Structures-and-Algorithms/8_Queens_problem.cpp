/**
 * @file 8_Queens_problem.cpp
 * @author Uzo Ochogu (uzoochogu@yahoo.com)
 * @brief This program finds the possible ways that 8 or n Queens can be arm_sized on a chess board such thay no queen can attack another queen
 * @version 0.1
 * @date 2022-08-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class Board
{
public:
    Board(int size) : m_size{size}
    {
        for(int i = 0; i < m_size; i++)
        {
            pieces.emplace_back();
            for(int j =0; j < m_size; j++)
            {
                pieces[i].push_back(false);
            }
        }
    };

    bool isSafe(int row, int column)
    {
        //int range = m_size - 1;
        for(int i = 0; i < m_size; i++)
        {
            //check across rows, columns, principal diagonal and secondary diagonal respectively.
            if(pieces[(row + i) % (m_size)][column] || 
               pieces[row][(column + i) % (m_size)] || 
               pieces[(row + i) % (m_size)][(column + i) % (m_size)] ||
               pieces[(row - i + m_size) % (m_size)][(column + i) % (m_size)])
            {
                return false;
            }
        }
        return true;
    };

    void place(int row, int column){ pieces[row][column] = true;};

    void remove(int row, int column){ pieces[row][column] = false;};

    std::string toString()
    {
        std::string output;
        for(auto i : pieces) //columns
        {
            for(auto j : i)//rows
            {
                if(j)
                    output.append("Q ");
                else
                    output.append("- ");
            }
            output += "\n"; 
        }
        return output;
    };

    int size()
    {
        return m_size;
    }

private:
    std::vector<std::vector<bool>> pieces;
    int m_size{0};
};

/**
 * @brief Utility function for solve8Queens()
 * 
 * @param board the board to solve
 * @param column keeps track of the current column being solved for
 */
void solve8QueensUtil(Board& board, int column)
{
    //std::cout << "solve8QueensUtil("  << "1 " << column << ") \n";
    if(column >= board.size())
    {
        std::cout << board.toString() << std::endl; 
        //std::cout << "cat";
    }
    else
    {
        //We need to place 1 queen in this column
        //for each possible place in this column
        for (int row = 0; row < board.size(); row++)
        {
            if(board.isSafe(row, column))
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
}

/**
 * @brief Prints the boards that satisfy the possible ways that 8 or n Queens can be arm_sized on a chess board such thay no queen can attack another queen
 * 
 * @param board 
 */
void solve8Queens(Board& board)
{
    solve8QueensUtil(board, 0);
}


int main()
{
    /* Board b(8);
    std::cout << b.toString();

    std::cout << b.isSafe(0, 0);

    b.place(2,3);

    std::cout << "\n" << b.toString() << "\n";

    std::cout <<  "\n" <<  b.isSafe(2,4) << "\n";

    b.remove(2,3);

    std::cout << b.toString();

    solve8Queens(b); */
    int size = 8;
    Board b(size);
    int row = 2;
    int column = 2;
    int m_size = 8;


    b.place(row,column);

    for(int i = 0; i < size; i++)
    {
        std::cout << "Rows:       " << (row + i) % (m_size) << ", " << column << "\n";
        std::cout << "Columns:    " << row << ", "<< (column + i) % (m_size) << "\n";
        std::cout << "P Diagonal: " << (row + i) % (m_size) << ", "<< (column + i) % (m_size)<< "\n" ;
        std::cout << "S Diagonal: " << (row - i + m_size) % (m_size)  << ", "<< (column + i) % (m_size)<< "\n";
    }
    


    return 0;
}
