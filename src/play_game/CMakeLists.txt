add_library(play_game
        play_game.c
        settings.c
        settings.h
)
target_link_libraries(play_game game_of_lines player_types)