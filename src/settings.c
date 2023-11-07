#include "settings.h"

struct game_settings get_settings_scan_console(void){
    char scan_ai_opponent = 'Y';
    printf("Play against computer ([y]/n)> ");
    scanf(" %c", &scan_ai_opponent);

    bool ai_opponent = scan_ai_opponent == 'Y' || scan_ai_opponent == 'y';

    int game_size_width;
    printf("Game size width> ");
    scanf("%d", &game_size_width);

    int game_size_height;
    printf("Game size height> ");
    scanf("%d", &game_size_height);

    int line_size;
    printf("Line size> ");
    scanf("%d", &line_size);

    struct game_settings scanned_settings = {
            .ai_opponent = ai_opponent,
            .game_size_width = game_size_width,
            .game_size_height = game_size_height,
            .line_size = line_size
    };

    return scanned_settings;
}