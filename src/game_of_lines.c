#include "game_of_lines.h"

struct board* initialize_board(int width, int height){
    int* cells = calloc(width * height, sizeof (int));

    struct board* board1 = malloc(sizeof(struct board));
    board1->cells = cells;
    board1->width = width;
    board1->height = height;

    return board1;
}

void free_board(struct board* board1){
    free(board1->cells);
    free(board1);
}

int get_cell(struct board board1, int x, int y){
    return board1.cells[board1.width * y + x];
}

void set_cell(struct board board1, int x, int y, int value){
    board1.cells[board1.width * y + x] = value;
}

bool put_column(struct board board1, int x, int value){
    // Go from bottom towards top, looking for first empty cell.
    for (int y = 0; y < board1.height; ++y) {
        if (get_cell(board1, x, y) != 0){
            continue;
        }

        set_cell(board1, x, y, value);
        return true;
    }

    return false;
}