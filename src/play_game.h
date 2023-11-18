#include <time.h>
#include "game_of_lines.h"
#include "settings.h"
#include "game_visualizer.h"

void play_game(get_settings settings_getter);
int game_of_lines(struct game_board board, struct game_rules rules, game_visualizer visualizer);
