
/*
 * The game checker represents an algorithm that determines
 * whether the game has been lost/won.
 *
 * The following game checker would make sense to include:
 * - Bruteforce check
 */

#include "game_of_lines.h"

#define NO_PLAYER (-1)

typedef int (*game_checker) (struct game_board board, struct game_rules rules);

int game_checker_nearest_slots(struct game_board board, struct game_rules rules);