#include "play_game.h"

// Funktionen er flyttet herind for at undgå cirkulære 'dependencies'
int game_of_lines(struct game_board board, struct game_rules rules, player_agent* players, int player_count, game_visualizer visualizer) {
    int turns = -1;
    int the_winner = -1;
    do {
        turns++;
        int whose_turn = turns % player_count;

        player_agent current_player = players[whose_turn];
        int move = current_player(board, rules);

        put_column(board, move, whose_turn);

        visualizer(board, rules);

        // the_winner = winner(...);

    } while (the_winner == -1);

    return the_winner;
}

void play_game(get_settings settings_getter) {
    srand(time(NULL));

    struct game_settings settings = settings_getter();

    struct game_board* board = initialize_board(settings.game_size_width, settings.game_size_height);
    struct game_rules rules = {.line_size = settings.line_size};

    // Use more dependency injection to prevent the function from concerning about implementation details.
    game_visualizer visualizer = game_visualizer_console;
    // ... checker here ...
    player_agent players[2];
    players[0] = player_agent_console;
    players[1] = settings.ai_opponent ? player_agent_random_ai : player_agent_console;

    int winner = game_of_lines(*board, rules, players, 2, visualizer);
    free_board(board);

    printf("Player %d won!", winner);
}
