#include "game_visualizer.h"

#define WIDTH_PER_CELL 2
#define DELIMITER_CHAR '|'
#define EMPTY_CELL_CHAR '_'

char digit_to_char(int digit){
    return '0' + digit;
}

char* render_board_console(struct game_board board) {
    int output_line_width = board.width * WIDTH_PER_CELL + 2; // 1 for '|' and 1 for new line
    int output_height = board.height + 1; // 1 for footer
    int size_of_output = output_line_width * output_height + 1; // 1 for null-terminator

    char* output = malloc(sizeof(char) * size_of_output);

    for (int y = 0; y < board.height; ++y) {
        int string_row_offset = output_line_width * y;

        output[string_row_offset + board.width * WIDTH_PER_CELL] = DELIMITER_CHAR;
        output[string_row_offset + board.width * WIDTH_PER_CELL + 1] = '\n';

        for (int x = 0; x < board.width; ++x) {
            int string_offset = x * WIDTH_PER_CELL + string_row_offset;

            int cell_value = get_cell(board, x, board.height - y - 1);
            char cell_char = digit_to_char(cell_value);
            if (cell_value == EMPTY_CELL){
                cell_char = EMPTY_CELL_CHAR;
            }

            output[string_offset] = DELIMITER_CHAR;
            output[string_offset + 1] = cell_char;
        }
    }

    // Footer
    int footer_string_offset = output_line_width * board.height;
    for (int x = 0; x < board.width; ++x) {
        int string_index = x * WIDTH_PER_CELL;

        output[footer_string_offset + string_index] = ' ';
        output[footer_string_offset + string_index + 1] = digit_to_char((x + 1) % 10);
    }

    output[size_of_output - 3] = ' ';
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
