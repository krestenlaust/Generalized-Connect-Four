#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY_CELL (-1)

struct game_board{
    int width;
    int height;
    int* cells;
};

struct game_rules{
    int line_size;
};

/**
 * Allocates a game_board instance, and its cells.
 * @param width The width of the game_board.
 * @param height The height of the game_board.
 * @return Reference to the newly allocated game_board.
 */
struct game_board* initialize_board(int width, int height);
/**
 * Deallocates the cells, and the game_board instance.
 * @param board The game_board to deallocate.
 */
void free_board(struct game_board* board);

int get_cell(struct game_board board, int x, int y);
void set_cell(struct game_board board, int x, int y, int value);

/**
 * Fills the first empty cell in a column.
 * A cell is zero when no player has populated the cell.
 * Cells are indexed from bottom-left corner, going horizontally, then upwards.
 * @param board The game_board whose cells to mutate.
 * @param x The column (indexed from left to right) to modify.
 * @param value The value to set.
 * @return Whether the column was empty and the value could be set.
 */
bool put_column(struct game_board board, int x, int value);