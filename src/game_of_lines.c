#include "game_of_lines.h"

struct game_board* initialize_board(int width, int height){
    int* cells = calloc(width * height, sizeof (int));

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
        if (get_cell(board, x, y) != 0){
            continue;
        }

        set_cell(board, x, y, value);
        return true;
    }

    return false;
}