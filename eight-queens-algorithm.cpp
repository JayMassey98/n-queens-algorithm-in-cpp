// ---------------------------------------------------------------------------
// This project is a self-taught exercise. For more examples of various coding
// projects, please see my GitHub portfolio at https://github.com/JayMassey98.
// ---------------------------------------------------------------------------

#include <cstdbool>
#include <cstdint>
#include <iostream>
#include <string>

#include "eight-queens-algorithm.h"


const uint8_t set_board_size = 8;
uint8_t board[set_board_size][set_board_size] = { 0 };


// output a human readable board of the selected size
void print_board_layout(uint8_t board_size)
{
   for (int i = 0; i < board_size; i++)
   {
       for (int j = 0; j < board_size; j++)
       {
           std::cout << board[i][j] << " ";
       }
       
       std::cout << std::endl;
   }
}


// determine if the selected queen position is valid
bool is_position_valid(uint8_t board_size, int row, int column)
{
    bool position_validity = true;
    
    for (int i = 0; i < column; i++)
    {
        // check if there is a queen to the left
        if (board[row][i] == 'Q')
        {
            position_validity = false;
            break;
        }
    }

    for (int i = row, j = column; i >= 0 && j >= 0; i--, j--)
    {
        // check if there is a queen in the upper left diagonal
        if (board[i][j] == 'Q')
        {
            position_validity = false;
            break;
        }
    }

    for (int i = row, j = column; i >= 0 && i < board_size
        && j >= 0 && j < board_size; i++, j--)
    {
        // check if there is a queen in the lower left diagonal
        if (board[i][j] == 'Q')
        {
            position_validity = false;
            break;
        }
    }

    return position_validity;
}


// set or reset the position of the current queen
bool place_n_queen(uint8_t board_size, int column)
{
    bool solution_found = false;
    
    // check if all queens have been successfully placed
    if (column >= board_size)
    {
        solution_found = true;
    }

    // skip the remaining calculations if a solution has been found
    if (solution_found == false)
    {
        // for each row, check placing of queen is possible or not
        for (int i = 0; i < board_size; i++)
        {
            // if the position is valid, place a queen there
            if (is_position_valid(board_size, i, column))
            {
                // add a queen to the current position
                board[i][column] = 'Q';

                // check the following column
                if (place_n_queen(board_size, column + 1))
                {
                    solution_found = true;
                    break;
                }

                // backtrack and remove the current queen
                board[i][column] = '-';
            }
        }
    }

    return solution_found;
}


// see if a solution for the selected board size exists
bool search_for_queens(uint8_t board_size)
{
    bool board_solution_found = false;
    
    // set all elements in the board array to 0
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            board[i][j] = '-';
        }
    }

    // determine if the first column does not contain a queen
    if (place_n_queen(board_size, 0) == false)
    {
        std::cout << "No solution exists for " << std::to_string(board_size) << " queens.\n";
    }
    else
    {
        // output the board to the user
        print_board_layout(board_size);

        board_solution_found = true;
    }

    return board_solution_found;
}


// entry point of program
int main()
{
    search_for_queens(set_board_size);
}
