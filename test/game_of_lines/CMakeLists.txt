# Game visualizer test
add_executable(test_game_visualizer test_game_visualizer.c)
target_link_libraries(test_game_visualizer game_of_lines)
add_test(NAME test_game_visualizer COMMAND test_game_visualizer)

# Game checker test
add_executable(test_game_checker test_game_checker.c)
target_link_libraries(test_game_checker game_of_lines)
add_test(NAME test_game_checker COMMAND test_game_checker)