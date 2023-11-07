#include <stdio.h>
#include <stdlib.h>

#include "game_of_lines.h"

void game_of_lines(int opponent_is_ai, int size_of_arena, int size_of_win_line);

int main(void) {
    int opponent_is_ai, size_of_arena, size_of_win_line;
    // scan_settings(...); should prompt the user for
    //  1. whether to play against AI or person,
    //  2. the size of the arena,
    //  3. how long a winning line needs to be.

    // Run the game
    game_of_lines(opponent_is_ai, size_of_arena, size_of_win_line);

    return 0;
}
