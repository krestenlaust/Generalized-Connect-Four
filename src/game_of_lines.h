#pragma once
#include <stdbool.h>
#include <stdlib.h>

struct board{
    int width;
    int height;
    int* cells;
};

struct rules{
    int line_size;
};

/**
 * Allocates a board instance, and its cells.
 * @param width The width of the board.
 * @param height The height of the board.
 * @return Reference to the newly allocated board.
 */
struct board* initialize_board(int width, int height);
/**
 * Deallocates the cells, and the board instance.
 * @param board1 The board to deallocate.
 */
void free_board(struct board* board1);

int get_cell(struct board board1, int x, int y);
void set_cell(struct board board1, int x, int y, int value);

/**
 * Fills the first empty cell in a column.
 * A cell is zero when no player has populated the cell.
 * Cells are indexed from bottom-left corner, going horizontally, then upwards.
 * @param board1 The board whose cells to mutate.
 * @param x The column (indexed from left to right) to modify.
 * @param value The value to set.
 * @return Whether the column was empty and the value could be set.
 */
bool put_column(struct board board1, int x, int value);