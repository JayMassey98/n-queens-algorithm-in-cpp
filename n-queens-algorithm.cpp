// ---------------------------------------------------------------------------
// This project is a self-taught exercise. For more examples of various coding
// projects, please see my GitHub portfolio at https://github.com/JayMassey98.
// ---------------------------------------------------------------------------

#include <chrono>
#include <cstdbool>
#include <cstdint>
#include <iostream>
#include <string>

#include "n-queens-algorithm.h"


const uint8_t max_board_size = 24;
uint8_t board[max_board_size][max_board_size] = { 0 };


// output a human readable board of the selected size
void print_board_layout(uint8_t board_size)
{
    for (uint8_t row = 0; row < board_size; row++)
    {
        for (uint8_t column = 0; column < board_size; column++)
        {
            std::cout << board[row][column] << " ";
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
        for (int row = 0; row < board_size; row++)
        {
            // if the position is valid, place a queen there
            if (is_position_valid(board_size, row, column))
            {
                // add a queen to the current position
                board[row][column] = 'Q';

                // check the following column
                if (place_n_queen(board_size, column + 1))
                {
                    solution_found = true;
                    break;
                }

                // backtrack and remove the current queen
                board[row][column] = '-';
            }
        }
    }

    return solution_found;
}


// see if a solution for the selected board size exists
bool search_for_queens(uint8_t board_size)
{
    auto start = std::chrono::steady_clock::now();
    bool board_solution_found = false;

    // set all elements in the board array to 0
    for (uint8_t row = 0; row < board_size; row++)
    {
        for (uint8_t column = 0; column < board_size; column++)
        {
            board[row][column] = '-';
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

    // calculate the time taken to find this solution
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = (end - start) / 1000;

    // output the time taken to find this solution
    std::cout << std::fixed << "\nThis solution was found in ~"
        << duration.count() << " ms." << std::endl;

    return board_solution_found;
}


// entry point of program
int main()
{
    std::cout << "N Queens Solution Finder\n\nInput a board size between 1 & " + std::to_string(max_board_size) + "."
        + "\nA solution will then be outputted.\nInput '0' below once you are done.\n";
    
    bool main_loop = true;
    int input_value = 0;

    while (main_loop == true)
    {        
        std::cout << "\nPlease enter your desired board size: ";
        std::cin >> input_value;

        // determine if the program should be stopped
        if (input_value == 0)
        {
            main_loop = false;
            break;
        }

        // determine if an invalid number was inputted
        if (input_value < 1 || input_value > max_board_size)
        {
            std::cout << "ERROR: Board size invalid!\n\n";

            // jump back to the start of the main loop
            continue;
        }

        std::cout << std::endl;

        search_for_queens(input_value);
    }
}
