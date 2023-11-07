# Game visualizer test
add_executable(test_player_types test_player_types.c)
target_link_libraries(test_player_types player_types)
add_test(NAME test_player_types COMMAND test_player_types)
