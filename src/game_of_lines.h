#include <stdbool.h>
#include <stdlib.h>

/**
 * A cell is zero when no player has populated the cell.
 * Cells are indexed from top-left corner, going horizontally, then downwards.
 */
struct board{
    int width;
    int height;
    int* cells;
};

struct board* initialize_board(int width, int height);

int get_cell(struct board board1, int x, int y);
void set_cell(struct board board1, int x, int y, int value);

/**
 * Fills the first empty cell in a column.
 * @param board1 The board whose cells to mutate.
 * @param x The column (indexed from left to right) to modify.
 * @param value The value to set.
 * @return Whether the column was empty and the value could be set.
 */
bool put_column(struct board board1, int x, int value);