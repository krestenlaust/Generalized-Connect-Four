
# We create a library for the functions in our game
add_library(game_of_lines
        game_of_lines.c
        game_of_lines.h
        game_checkers.c
        game_checkers.h
        game_visualizer.c
        game_visualizer.h
)
target_include_directories(game_of_lines PUBLIC .)

add_library(player_types
        player_types.c
        player_types.h
)
target_include_directories(player_types PUBLIC .)

add_library(play_game
        play_game.c
        settings.c
        settings.h
)
target_link_libraries(play_game game_of_lines player_types)

# Entry point
add_executable(entry_point
        entry_point.c
)
target_link_libraries(entry_point play_game)