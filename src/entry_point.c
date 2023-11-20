#include "play_game/play_game.h"

int main(void) {
    // Run the game
    setbuf(stdout, 0);

    // Pass settings getter using Dependency Injection.
    play_game(get_settings_scan_console);

    return 0;
}