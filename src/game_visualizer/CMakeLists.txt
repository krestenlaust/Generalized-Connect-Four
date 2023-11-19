add_library(game_visualizer
        game_visualizer.c
        game_visualizer.h
)
target_include_directories(game_visualizer PUBLIC .)

# Dependencies
target_link_libraries(game_visualizer game_of_lines)