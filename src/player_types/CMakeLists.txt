# Library for player agents
add_library(player_types
        player_types.c
        player_types.h
)
target_include_directories(player_types PUBLIC .)

# Dependencies
target_link_libraries(player_types game_of_lines)