#include "game_checkers.h"

int count_consecutive_value(struct game_board board, int x, int y, int direction_x, int direction_y, int value){
    int new_x = x + direction_x;
    int new_y = y + direction_y;
    int cell_value = get_cell(board, new_x, new_y);

    // Base-case 1, outside board.
    if (cell_value == CELL_NON_EXISTENT){
        return 0;
    }

    // Base-case 2, cell value doesn't match.
    if (cell_value != value){
        return 0;
    }

    // Recursive step, count next cell if is of value.
    return 1 + count_consecutive_value(board, new_x, new_y, direction_x, direction_y, value);
}

bool is_board_full(struct game_board board){
    for (int i = 0; i < board.width; ++i) {
        if (find_first_empty_in_column(board, i) != CELL_NON_EXISTENT){
            return false;
        }
    }

    return true;
}

int game_checker_nearest_slots(struct game_board board, struct game_rules rules){
    int x = board.last_move_x;
    int y = find_first_empty_in_column(board, x);

    // Get cell below empty.
    if (y == CELL_NON_EXISTENT){
        y = board.height - 1;
    }else{
        y = y - 1;
    }

    if (x < 0 || x >= board.width || y < 0 || y >= board.height){
        return NOT_FINISHED;
    }

    int search_value = get_cell(board, x, y);
    if (search_value == CELL_NON_EXISTENT){
        return NOT_FINISHED;
    }

    // Check diagonals and horisontal
    for (int dir_y = -1; dir_y <= 1; ++dir_y) {
        int dir_x = -1;

        int left = count_consecutive_value(board, x, y, dir_x, dir_y, search_value);
        int right = count_consecutive_value(board, x, y, -dir_x, -dir_y, search_value);

        // Tokens to the left and to the right (+1 in middle) is long enough.
        if (left + right + 1 >= rules.line_size){
            return search_value;
        }
    }

    int downwards = count_consecutive_value(board, x, y, 0, -1, search_value);
    if (downwards + 1 >= rules.line_size){
        return search_value;
    }

    if (is_board_full(board)){
        return DRAW;
    }

    return NOT_FINISHED;
}