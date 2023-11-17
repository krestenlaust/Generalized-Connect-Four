#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

/**
 * This struct is only used by play_game to represent player input.
 * Examples of expansion
 *  - struct game_settings get_settings_args(...);
 *  - struct game_settings get_settings_file(...);
 */
struct game_settings {
    bool ai_opponent;
    int game_size_width;
    int game_size_height;
    int line_size;
};

typedef struct game_settings(*get_settings)(void);

struct game_settings get_settings_scan_console(void);


char* format_settings(struct game_settings settings);