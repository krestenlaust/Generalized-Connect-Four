
# We create a library for the functions in our game
add_library(game_of_lines
        game_of_lines.c
        game_of_lines.h
        settings.c
        settings.h
        game_checkers.c
        game_checkers.h
        game_visualizer.c
        game_visualizer.h
)

add_library(player_types
        player_types.c
        player_types.h
)

# Make header files in the current folder for #include
target_include_directories(game_of_lines PUBLIC .)
target_include_directories(player_types PUBLIC .)

add_executable(play_game play_game.c)
target_link_libraries(play_game game_of_lines player_types)
