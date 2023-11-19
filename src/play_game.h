#include <time.h>
#include "game_of_lines.h"
#include "settings.h"
#include "game_visualizer.h"
#include "player_types.h"
#include "game_checkers.h"

void play_game(get_settings settings_getter);
int game_of_lines(struct game_board board, struct game_rules rules, player_agent* players, int player_count, game_visualizer visualizer, game_checker checker);
