// ---------------------------------------------------------------------------
// This project is a self-taught exercise. For more examples of various coding
// projects, please see my GitHub portfolio at https://github.com/JayMassey98.
// ---------------------------------------------------------------------------

// --------------------------------------------------------------------------
// PURPOSE: Use backtracking to determine a solution for an n-queens problem.
// --------------------------------------------------------------------------

#pragma once

#include <cstdbool>
#include <cstdint>


// output a human readable board of the selected size
void print_board_layout(uint8_t board_size);

// determine if the selected queen position is valid
bool is_position_valid(uint8_t board_size, int row, int column);

// set or reset the position of the current queen
bool place_n_queen(uint8_t board_size, int column);

// see if a solution for the selected board size exists
bool search_for_queens(uint8_t board_size);

// entry point of program
int main();
