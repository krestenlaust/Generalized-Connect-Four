#include <assert.h>
#include "game_of_lines.h"

void test_initialize_board_zeroes(void);
void test_set_cell(void);
void test_get_cell(void);
void test_get_cell_outside(void);
void test_set_cell_outside(void);
void test_put_column_empty(void);
void test_put_column_partial_empty(void);
void test_put_column_full(void);
void test_put_column_outside(void);
void test_find_first_empty_in_column_empty(void);
void test_find_first_empty_in_column_partial_full(void);
void test_find_first_empty_in_column_full(void);

int main(void) {
    test_initialize_board_zeroes();
    test_set_cell();
    test_get_cell();
    test_get_cell_outside();
    test_set_cell_outside();

    test_put_column_empty();
    test_put_column_partial_empty();
    test_put_column_full();
    test_put_column_outside();

    test_find_first_empty_in_column_empty();
    test_find_first_empty_in_column_partial_full();
    test_find_first_empty_in_column_full();
}

void test_initialize_board_zeroes(void){
    struct game_board* board = initialize_board(5, 5);

    for (int i = 0; i < 5 * 5; ++i) {
        assert(board->cells[i] == EMPTY_CELL);
    }

    free_board(board);
}

void test_set_cell(void){
    struct game_board* board = initialize_board(5, 5);
    set_cell(*board, 0, 0, 1);
    set_cell(*board, 4, 4, 2);

    int cell_0_0 = board->cells[0];
    int cell_4_4 = board->cells[4 * 5 + 4];

    assert(cell_0_0 == 1);
    assert(cell_4_4 == 2);

    free_board(board);
}

void test_get_cell(void){
    struct game_board* board1 = initialize_board(5, 5);
    board1->cells[0] = 1;
    board1->cells[4 * 5 + 4] = 2;

    int cell_0_0 = get_cell(*board1, 0, 0);
    int cell_4_4 = get_cell(*board1, 4, 4);

    assert(cell_0_0 == 1);
    assert(cell_4_4 == 2);

    free_board(board1);
}

/**
 * This test is to ensure this behavior stays consistent.
 */
void test_get_cell_outside(void){
    struct game_board* board = initialize_board(5, 5);

    int cell_5_5 = get_cell(*board, 5, 5);
    int cell_minus1_minus1 = get_cell(*board, -1, -1);
    int cell_3_3 = get_cell(*board, 3, 3);

    assert(cell_5_5 == CELL_NON_EXISTENT);
    assert(cell_minus1_minus1 == CELL_NON_EXISTENT);
    assert(cell_3_3 == EMPTY_CELL);

    free_board(board);
}

/**
 * This test is to ensure this behavior stays consistent.
 */
void test_set_cell_outside(void){
    struct game_board* board = initialize_board(5, 5);

    bool cell_5_5 = set_cell(*board, 5, 5, 1);
    bool cell_minus1_minus1 = set_cell(*board, -1, -1, 1);
    bool cell_3_3 = set_cell(*board, 3, 3, 1);

    assert(cell_5_5 == false);
    assert(cell_minus1_minus1 == false);
    assert(cell_3_3 == true);

    free_board(board);
}

void test_put_column_outside(void){
    struct game_board* board = initialize_board(5, 5);

    bool column_0_valid = put_column(*board, 0, 1);
    bool column_5_invalid = put_column(*board, 5, 1);

    assert(column_0_valid == true);
    assert(column_5_invalid == false);

    free_board(board);
}

void test_put_column_empty(void){
    struct game_board* board = initialize_board(5, 5);

    bool column_0 = put_column(board, 0, 1);
    bool column_4 = put_column(board, 4, 2);

    int cell_0_0_filled = get_cell(*board, 0, 0);
    int cell_0_1_empty = get_cell(*board, 0, 1);
    int cell_4_0_filled = get_cell(*board, 4, 0);
    int cell_4_1_empty = get_cell(*board, 4, 1);

    assert(column_0 == true);
    assert(cell_0_0_filled == 1);
    assert(cell_0_1_empty == EMPTY_CELL);

    assert(column_4 == true);
    assert(cell_4_0_filled == 2);
    assert(cell_4_1_empty == EMPTY_CELL);

    free_board(board);
}

void test_put_column_partial_empty(void){
    struct game_board* board = initialize_board(5, 5);
    set_cell(*board, 0, 0, 1);

    bool column_0_first = put_column(board, 0, 1);
    bool column_0_second = put_column(board, 0, 2);

    int cell_0_0 = get_cell(*board, 0, 0);
    int cell_0_1 = get_cell(*board, 0, 1);
    int cell_0_2 = get_cell(*board, 0, 2);
    int cell_0_3_empty = get_cell(*board, 0, 3);

    assert(column_0_first == true);
    assert(column_0_second == true);
    assert(cell_0_0 == 1);
    assert(cell_0_1 == 1);
    assert(cell_0_2 == 2);
    assert(cell_0_3_empty == EMPTY_CELL);

    free_board(board);
}

void test_put_column_full(void){
    struct game_board* board = initialize_board(3, 3);
    set_cell(*board, 0, 0, 1);
    set_cell(*board, 0, 1, 1);
    set_cell(*board, 0, 2, 1);

    bool column_0 = put_column(board, 0, 2);

    int cell_0_0 = get_cell(*board, 0, 0);
    int cell_0_1 = get_cell(*board, 0, 1);
    int cell_0_2 = get_cell(*board, 0, 2);

    assert(column_0 == false);
    assert(cell_0_0 == 1);
    assert(cell_0_1 == 1);
    assert(cell_0_2 == 1);

    free_board(board);
}

void test_find_first_empty_in_column_empty(void){
    struct game_board* board = initialize_board(1, 3);

    int y = find_first_empty_in_column(*board, 0);

    assert(y == 0);

    free_board(board);
}

void test_find_first_empty_in_column_partial_full(void){
    struct game_board* board = initialize_board(1, 3);
    set_cell(*board, 0, 0, 1);

    int y = find_first_empty_in_column(*board, 0);

    assert(y == 1);

    free_board(board);
}

void test_find_first_empty_in_column_full(void){
    struct game_board* board = initialize_board(1, 3);
    set_cell(*board, 0, 0, 1);
    set_cell(*board, 0, 1, 1);
    set_cell(*board, 0, 2, 1);

    int y = find_first_empty_in_column(*board, 0);

    assert(y == CELL_NON_EXISTENT);

    free_board(board);
}