# We create a library for the functions in our game
add_library(game_of_lines
        game_of_lines.c
        game_of_lines.h
        game_checkers.c
        game_checkers.h
)
target_include_directories(game_of_lines PUBLIC .)