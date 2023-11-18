#include "game_visualizer.h"

#define WIDTH_PER_CELL 2

char* render_board_console(struct game_board board) {
    int output_line_width = board.width * WIDTH_PER_CELL + 2; // |x|x|x|x|\n
    int output_height = board.height + 1;
    int size_of_output = output_line_width * output_height + 1;

    char* output = malloc(sizeof(char) * size_of_output);

    for (int y = 0; y < board.height; ++y) {
        int array_offset_y = output_line_width * y;

        for (int x = 0; x < board.width; ++x) {
            int array_offset_x = x * WIDTH_PER_CELL;
            int array_offset = array_offset_x + array_offset_y;

            int cell_value = get_cell(board, x, board.height - y - 1);
            char cell_char = '0' + cell_value;
            if (cell_value == EMPTY_CELL){
                cell_char = '_';
            }

            output[array_offset] = '|';
            output[array_offset + 1] = cell_char;
        }

        output[array_offset_y + board.width * WIDTH_PER_CELL] = '|';
        output[array_offset_y + board.width * WIDTH_PER_CELL + 1] = '\n';
    }

    // Footer
    for (int x = 0; x < output_line_width - 1; ++x) {
        char column_char;
        if (x % WIDTH_PER_CELL == 1){
            column_char = '0' + ((x + 1) / WIDTH_PER_CELL);
        }else{
            column_char = '_';
        }

        output[output_line_width * board.height + x] = column_char;
    }

    output[size_of_output - 2] = '\n';
    output[size_of_output - 1] = '\0';

    return output;
}

char* render_rules_console(struct game_rules rules) {
    char* t = calloc(30, sizeof(char));
    sprintf(t, "Rules:\n- Lines to win: %d\n", rules.line_size);
    return t;
}

void game_visualizer_console(struct game_board board, struct game_rules rules) {
    printf("%s\n", render_rules_console(rules));
    printf("%s\n", render_board_console(board));
}
