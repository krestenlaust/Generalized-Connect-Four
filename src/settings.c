#include "settings.h"

struct game_settings get_settings_scan_console(void){
    char scan_ai_opponent;
    printf("Play against computer [Y/n]>");
    scanf("%c", &scan_ai_opponent);
    // Default to Yes.
    if (scan_ai_opponent == '\r' || scan_ai_opponent == '\n'){
        scan_ai_opponent = 'y';
    }

    bool ai_opponent = scan_ai_opponent == 'Y' || scan_ai_opponent == 'y';

    int game_size_width;
    printf("Game size width>");
    scanf("%d", &game_size_width);

    int game_size_height;
    printf("Game size height>");
    scanf("%d", &game_size_height);

    int line_size;
    printf("Line size>");
    scanf("%d", &line_size);

    struct game_settings scanned_settings = {
            .ai_opponent = ai_opponent,
            .game_size_width = game_size_width,
            .game_size_height = game_size_height,
            .line_size = line_size
    };

    return scanned_settings;
}

char* format_settings(struct game_settings settings){
    // Rough estimate of string length.
    char* settings_string = calloc(45, sizeof(char));

    sprintf(settings_string, "AI opponent:\t%d\nBoard size:\t%d X %d\nLine size:\t%d",
            settings.ai_opponent,
            settings.game_size_width,
            settings.game_size_height,
            settings.line_size);

    return settings_string;
}