# Game visualizer test
add_executable(test_game_visualizer test_game_visualizer.c)
target_link_libraries(test_game_visualizer game_of_lines)
add_test(NAME test_game_visualizer COMMAND test_game_visualizer)

# Game checker test
add_executable(test_game_checker test_game_checker.c)
target_link_libraries(test_game_checker game_of_lines)
add_test(NAME test_game_checker COMMAND test_game_checker)

# Game of lines (overall and helper) test
add_executable(test_game_of_lines test_game_of_lines.c)
target_link_libraries(test_game_of_lines game_of_lines)
add_test(NAME test_game_of_lines COMMAND test_game_of_lines)