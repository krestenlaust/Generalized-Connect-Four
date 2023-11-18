
/*
 * A player type represents each of the two players in fire-på-stribe.
 *
 * The following player types would make sense to include:
 * - Random AI
 * - Console input
 * - Smart AI
 */

#include "game_of_lines.h"

typedef int (*player_agent)(struct game_board board, struct game_rules);

int player_agent_console(struct game_board board, struct game_rules rules);
int player_agent_random_ai(struct game_board board, struct game_rules rules);