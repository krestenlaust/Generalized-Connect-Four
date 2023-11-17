#include "play_game.h"

// Funktionen er flyttet herind for at undgå cirkulære 'dependencies'
void game_of_lines(struct board board1, struct rules rules1, game_visualizer visualizer) {

    int current_turn = 0;
    int whose_turn = 1;
    int the_winner = -1;
    do {
        int move = 0;
        // scan_move(...);
        //     or
        // ai_move(...);

        put_column(board1, move, whose_turn);

        visualizer(board1, rules1);

        // the_winner = winner(...);

    } while (the_winner == -1);

    printf("Player %d won!", the_winner);
}

void play_game(get_settings settings_getter) {
    struct game_settings settings = settings_getter();

    struct board* board1 = initialize_board(settings.game_size_width, settings.game_size_height);
    struct rules rules1 = {.line_size = settings.line_size};

    // Use more dependency injection to prevent the function from concerning about implementation details.
    game_visualizer visualizer = game_visualizer_console;

    game_of_lines(*board1, rules1, visualizer);
}
