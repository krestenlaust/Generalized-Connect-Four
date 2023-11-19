
add_subdirectory(game_of_lines)

add_subdirectory(player_types)

add_subdirectory(play_game)

# Entry point
add_executable(entry_point
        entry_point.c
)
target_link_libraries(entry_point play_game)