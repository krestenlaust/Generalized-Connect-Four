#include <assert.h>
#include "game_checkers.h"

void test_nearest_slots_horisontal_win(void);
void test_nearest_slots_vertical_win(void);
void test_nearest_slots_empty(void);
void test_nearest_slots_diagonal_1(void);
void test_nearest_slots_diagonal_2(void);

// Write unit tests!
int main(void) {
    test_nearest_slots_horisontal_win();
    test_nearest_slots_vertical_win();
    test_nearest_slots_empty();
    test_nearest_slots_diagonal_1();
    test_nearest_slots_diagonal_2();
}

void assert_game_checker_horisontal_win(game_checker checker){
    int board_setup[] = {
            EMPTY_CELL, 2, 1, 2, 1,
            EMPTY_CELL, 1, 1, 1, 1,
            EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL
    };

    struct game_board board = {.width = 5, .height = 3, .cells = board_setup, .last_move_x = 2};
    struct game_rules rules = {.line_size = 4};

    int winner = checker(board, rules);

    assert(winner == 1);
}

void assert_game_checker_vertical_win(game_checker checker){
    int board_setup[] = {
            EMPTY_CELL, 1, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL,
            EMPTY_CELL, 1, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL,
            EMPTY_CELL, 1, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL
    };

    struct game_board board = {.width = 5, .height = 3, .cells = board_setup, .last_move_x = 1};
    struct game_rules rules = {.line_size = 3};

    int winner = checker(board, rules);

    assert(winner == 1);
}

void assert_game_checker_empty(game_checker checker){
    int board_setup[] = {
            EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL,
            EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL,
            EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL
    };

    struct game_board board = {.width = 5, .height = 3, .cells = board_setup, .last_move_x = 0};
    struct game_rules rules = {.line_size = 3};

    int winner = checker(board, rules);

    assert(winner == NO_PLAYER);
}

void assert_game_checker_diagonal_1(game_checker checker){
    int board_setup[] = {
            EMPTY_CELL, 2, 2, 1, EMPTY_CELL,
            EMPTY_CELL, 2, 1, EMPTY_CELL, EMPTY_CELL,
            EMPTY_CELL, 1, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL
    };

    struct game_board board = {.width = 5, .height = 3, .cells = board_setup, .last_move_x = 2};
    struct game_rules rules = {.line_size = 3};

    int winner = checker(board, rules);

    assert(winner == 1);
}

void assert_game_checker_diagonal_2(game_checker checker){
    int board_setup[] = {
            EMPTY_CELL, 1, 2, 2, EMPTY_CELL,
            EMPTY_CELL, EMPTY_CELL, 1, 2, EMPTY_CELL,
            EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, 1, EMPTY_CELL
    };

    struct game_board board = {.width = 5, .height = 3, .cells = board_setup, .last_move_x = 2};
    struct game_rules rules = {.line_size = 3};

    int winner = checker(board, rules);

    assert(winner == 1);
}

void test_nearest_slots_horisontal_win(void){
    assert_game_checker_horisontal_win(game_checker_nearest_slots);
}

void test_nearest_slots_vertical_win(void){
    assert_game_checker_vertical_win(game_checker_nearest_slots);
}

void test_nearest_slots_empty(void){
    assert_game_checker_empty(game_checker_nearest_slots);
}

void test_nearest_slots_diagonal_1(void){
    assert_game_checker_diagonal_1(game_checker_nearest_slots);
}

void test_nearest_slots_diagonal_2(void){
    assert_game_checker_diagonal_2(game_checker_nearest_slots);
}