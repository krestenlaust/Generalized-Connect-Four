#pragma once
#include <stdio.h>
#include "game_of_lines.h"

/*
* The game visualizer interacts with IO to display the game to the user.
 *
 * The following game visualizers should exist:
 * - Console visualizer
*/

typedef void (*game_visualizer)(struct game_board, struct game_rules);

void game_visualizer_console(struct game_board board, struct game_rules rules);

/**
 * Renders the game_board into a null-terminated string.
 * NOTE: I don't feel like adding tests for these functions, but it's possible.
 * @param board The game_board to render.
 * @return Null-terminated string.
 */
char* render_board_console(struct game_board board);
char* render_rules_console(struct game_rules rules);

char digit_to_char(int digit);