#include "game_visualizer.h"

/*
* The game visualizer interacts with IO to display the game to the user.
 *
 * The following game visualizers should exist:
 * - Console visualizer
*/

char* render_board_console(struct board board1) {
    int output_line_width = board1.width * 2 + 2; // |x|x|x|x|\n
    int output_height = board1.height + 1;
    int size_of_output = output_line_width * output_height + 1;

    char* output = malloc(sizeof(char) * size_of_output);

    for (int y = 0; y < board1.height; ++y) {
        int array_offset_y = output_line_width * y;

        for (int x = 0; x < board1.width; ++x) {
            int array_offset_x = x * 2;
            int array_offset = array_offset_x + array_offset_y;

            int cell_value = get_cell(board1, x, board1.height - y - 1);

            output[array_offset] = '|';
            output[array_offset + 1] = '0' + cell_value;
        }

        output[array_offset_y + board1.width * 2] = '|';
        output[array_offset_y + board1.width * 2 + 1] = '\n';
    }

    // Footer
    for (int x = 0; x < output_line_width; ++x) {
        output[x + output_line_width * board1.height] = '_';
    }

    output[size_of_output - 1] = '\0';

    return output;
}

char* render_rules_console(struct rules rules1) {
    char* t = malloc(sizeof(char));
    t[0] = '\0';
    return t;
}

void game_visualizer_console(struct board board1, struct rules rules1) {
    printf("%s\n", render_rules_console(rules1));
    printf("%s\n", render_board_console(board1));
}
