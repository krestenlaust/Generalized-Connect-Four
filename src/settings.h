#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

/**
 * This struct is only used by play_game to represent player input.
 */
struct game_settings {
    bool ai_opponent;
    int game_size_width;
    int game_size_height;
    int line_size;
};

struct game_settings get_settings_scan_console(void);
// Examples of expansion
//struct game_settings get_settings_args(void);
//struct game_settings get_settings_file(void);

char* format_settings(struct game_settings settings);