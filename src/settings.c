#include "settings.h"

char* format_settings(struct game_settings settings){
    // Rough estimate of string length.
    char* settings_string = calloc(sizeof(char) * 45);

    sprintf(settings_string, "AI opponent:\t%d\nGame size:\t%d*%d\nLine size:\t%d",
            settings.ai_opponent,
            settings.game_size_width,
            settings.game_size_height,
            settings.line_size);

    return settings_string;
}