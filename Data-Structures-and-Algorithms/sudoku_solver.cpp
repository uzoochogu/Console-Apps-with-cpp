#include <iostream>
#include <array>
#include <bitset>
#include <vector>

//utility function to return cell number
constexpr std::size_t
get_cell(std::size_t row, std::size_t column) noexcept
{
    return (row / 3) * 3 + column / 3;
}

//Utilitu function to return the next row
constexpr std::size_t
get_next_row(std::size_t row, std::size_t column) noexcept
{
    return row + (column + 1)/ 9;
}

constexpr std::size_t
get_next_column(std::size_t column) noexcept
{
    return (column + 1) % 9;
}



class Solution
{
public:
    void solveSudoku(std::vector<std::vector<char>> &board) const noexcept
    {
        /*
        Note: input is guaranteed to be a valid board using only '1'-'9' and '.' with a uniquesolution.
        Solution should modify board, not return a new one.
        */

        //We'll use bitsets to map if a row, column or cell contains a particular value between 1-9
        std::array<std::bitset<9>, 9> row_contains = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        std::array<std::bitset<9>, 9> col_contains = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        std::array<std::bitset<9>, 9> cell_contains = {0, 0, 0, 0, 0, 0, 0, 0, 0};

        //Map out our given integers and set bitsets
        for( std::size_t row = 0; row < 9; ++row)
        {
            for(std::size_t column = 0; column < 9; ++column)
            {
                char digit;
                if((digit = board[row][column]) != '.')
                {
                    std::size_t digit_idx = digit - '1';  //1-9 is mapped to 0-8
                    row_contains[row].set(digit_idx);
                    col_contains[column].set(digit_idx);
                    std::size_t cell = get_cell(row, column);
                    cell_contains[cell].set(digit_idx);
                }
            }
        }
        //Give out info to the solver
        solve(board, 0, 0, row_contains, col_contains, cell_contains);  //Since we are assured that an input has a unique solution so no need to check that it is solved
    }

private:
    
    //Returns the next empty position
    static constexpr std::pair<std::size_t, std::size_t>
    next_empty_position(std::vector<std::vector<char>> &board, std::size_t row, std::size_t column) noexcept
    {
        while (row != 9) //We move from the first row to the last
        {
            if(board[row][column] == '.')
            {
                return {row, column};
            }
            row = get_next_row(row, column);
            column = get_next_column(column);
        }

        return {9, 0};  //Return values if no more rows left
    }

    static bool
    solve(std::vector<std::vector<char>> &board, std::size_t const row_start, std::size_t const col_start,
          std::array<std::bitset<9>, 9> &row_contains,
          std::array<std::bitset<9>, 9> &col_contains,
          std::array<std::bitset<9>, 9> &cell_contains) noexcept
    {
        auto [row, column] = next_empty_position(board, row_start, col_start);

        if(row == 9) //end of board  #base case 
        {
            return true;
        }

        std::size_t const cell = get_cell(row, column);
        std::bitset<9> const contains = row_contains[row] | col_contains[column] | cell_contains[cell]; //computes already used numbers
        if(contains.all()) 
        {
            return false; //all digits have been used
        }

        for(std::size_t digit_idx = 0; digit_idx < 9; ++digit_idx) //If thrre are still some digit then backtrack
        {
            if(!contains[digit_idx])
            {
                board[row][column] = static_cast<char>(digit_idx + '1'); //make a guess
                row_contains[row].set(digit_idx); //mark the digit as being used
                col_contains[column].set(digit_idx);
                cell_contains[cell].set(digit_idx);
                if(solve(board, row, column, row_contains, col_contains, cell_contains)) //return value of solve indicates if it succeeds or not
                {
                    return true;
                }

                //if false undo the guess and move to next guess in next iteration
                row_contains[row].reset(digit_idx); //unmark the digit
                col_contains[column].reset(digit_idx);
                cell_contains[cell].reset(digit_idx);
            }
        }
        board[row][column] = '.'; //If none of the guesses succeeds reset current location to blank
        return false; //wasn't able to complete the board given current input


    }      

};

//Utility function to print board
void print_board(std::vector<std::vector<char>> board)
{
    for(std::size_t row = 0; row < 9; ++row)
    {
        for(std::size_t column = 0; column < 9; ++column)
        {
            std::cout << board[row][column] << ", ";
        }
        std::cout << std::endl;
    }
} 

//Converts the flat board to a vector of vector of chars
std::vector<std::vector<char>> flat_board_to_vec_vec(std::array<char, 81> const flat_board)
{
    std::vector<std::vector<char>> board;
    board.reserve(9);  //Keep 9 empty spaces
    for(std::size_t row = 0; row < 9; ++row)
    {
        std::vector<char> this_row;
        this_row.reserve(9);
        for(std::size_t column = 0; column < 9; ++column)
        {
            this_row.push_back(flat_board[row * 9 + column]);
        }
        board.push_back(this_row);
    }
    return board;    
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

    std::array<char, 81> const flat_expected= {'5', '3', '4', '6', '7', '8', '9', '1', '2',
                                               '6', '7', '2', '1', '9', '5', '3', '4', '8',
                                               '1', '9', '8', '3', '4', '2', '5', '6', '7',
                                               '8', '5', '9', '7', '6', '1', '4', '2', '3',
                                               '4', '2', '6', '8', '5', '3', '7', '9', '1',
                                               '7', '1', '3', '9', '2', '4', '8', '5', '6',
                                               '9', '6', '1', '5', '3', '7', '2', '8', '4',
                                               '2', '8', '7', '4', '1', '9', '6', '3', '5',
                                               '3', '4', '5', '2', '8', '6', '1', '7', '9',};

    std::vector<std::vector<char>> board = flat_board_to_vec_vec(flat_board);     
    std::vector<std::vector<char>> const expected = flat_board_to_vec_vec(flat_expected);

    Solution soln;

    std::cout << "initial\n";
    print_board(board);   

    std::cout << "\nexpected\n";
    print_board(expected);

    soln.solveSudoku(board);
    std::cout << "\n\n" <<(board == expected ? "success!!" : "Nope :(") << std::endl;
    std::cout << "\nactual\n";
    print_board(board);                                                              
    return 0;
}