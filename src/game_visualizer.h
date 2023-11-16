#pragma once
#include <stdio.h>
#include "game_of_lines.h"

typedef void (*game_visualizer)(struct board, struct rules);

void game_visualizer_console(struct board board1, struct rules rules1);

char* render_board_console(struct board board1);
char* render_rules_console(struct rules rules1);