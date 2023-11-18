#include "game_of_lines.h"

struct game_board* initialize_board(int width, int height){
    const int total_size = width * height;
    int* cells = malloc(sizeof(int) * total_size);
    memset(cells, EMPTY_CELL, sizeof(int) * total_size);

    struct game_board* board = malloc(sizeof(struct game_board));
    board->cells = cells;
    board->width = width;
    board->height = height;

    return board;
}

void free_board(struct game_board* board){
    free(board->cells);
    free(board);
}

int get_cell(struct game_board board, int x, int y){
    return board.cells[board.width * y + x];
}

void set_cell(struct game_board board, int x, int y, int value){
    board.cells[board.width * y + x] = value;
}

bool put_column(struct game_board board, int x, int value){
    // Go from bottom towards top, looking for first empty cell.
    for (int y = 0; y < board.height; ++y) {
        if (get_cell(board, x, y) == EMPTY_CELL) {
            set_cell(board, x, y, value);
            return true;
        }
    }

    return false;
}