#include <assert.h>
#include "game_of_lines.h"

void test_initialize_board_zeroes(void);
void test_set_cell(void);
void test_get_cell(void);
void test_put_column_empty(void);
void test_put_column_partial_empty(void);
void test_put_column_full(void);

int main(void) {
    test_initialize_board_zeroes();
    test_set_cell();
    test_get_cell();

    test_put_column_empty();
    test_put_column_partial_empty();
    test_put_column_full();
}

void test_initialize_board_zeroes(void){
    struct board* board1 = initialize_board(5, 5);

    for (int i = 0; i < 5 * 5; ++i) {
        assert(board1->cells[i] == 0);
    }

    free_board(board1);
}

void test_set_cell(void){
    struct board* board1 = initialize_board(5, 5);
    set_cell(*board1, 0, 0, 1);
    set_cell(*board1, 4, 4, 2);

    int cell_0_0 = board1->cells[0];
    int cell_4_4 = board1->cells[4 * 5 + 4];

    assert(cell_0_0 == 1);
    assert(cell_4_4 == 2);

    free_board(board1);
}

void test_get_cell(void){
    struct board* board1 = initialize_board(5, 5);
    board1->cells[0] = 1;
    board1->cells[4 * 5 + 4] = 2;

    int cell_0_0 = get_cell(*board1, 0, 0);
    int cell_4_4 = get_cell(*board1, 4, 4);

    assert(cell_0_0 == 1);
    assert(cell_4_4 == 2);

    free_board(board1);
}

void test_put_column_empty(void){
    struct board* board1 = initialize_board(5, 5);

    bool column_0 = put_column(*board1, 0, 1);
    bool column_4 = put_column(*board1, 4, 2);

    int cell_0_0_filled = get_cell(*board1, 0, 0);
    int cell_0_1_empty = get_cell(*board1, 0, 1);
    int cell_4_0_filled = get_cell(*board1, 4, 0);
    int cell_4_1_empty = get_cell(*board1, 4, 1);

    assert(column_0 == true);
    assert(cell_0_0_filled == 1);
    assert(cell_0_1_empty == 0);

    assert(column_4 == true);
    assert(cell_4_0_filled == 2);
    assert(cell_4_1_empty == 0);

    free_board(board1);
}

void test_put_column_partial_empty(void){
    struct board* board1 = initialize_board(5, 5);
    set_cell(*board1, 0, 0, 1);

    bool column_0_first = put_column(*board1, 0, 1);
    bool column_0_second = put_column(*board1, 0, 2);

    int cell_0_0 = get_cell(*board1, 0, 0);
    int cell_0_1 = get_cell(*board1, 0, 1);
    int cell_0_2 = get_cell(*board1, 0, 2);
    int cell_0_3_empty = get_cell(*board1, 0, 3);

    assert(column_0_first == true);
    assert(column_0_second == true);
    assert(cell_0_0 == 1);
    assert(cell_0_1 == 1);
    assert(cell_0_2 == 2);
    assert(cell_0_3_empty == 0);

    free_board(board1);
}

void test_put_column_full(void){
    struct board* board1 = initialize_board(3, 3);
    set_cell(*board1, 0, 0, 1);
    set_cell(*board1, 0, 1, 1);
    set_cell(*board1, 0, 2, 1);

    bool column_0 = put_column(*board1, 0, 2);

    int cell_0_0 = get_cell(*board1, 0, 0);
    int cell_0_1 = get_cell(*board1, 0, 1);
    int cell_0_2 = get_cell(*board1, 0, 2);

    assert(column_0 == false);
    assert(cell_0_0 == 1);
    assert(cell_0_1 == 1);
    assert(cell_0_2 == 1);

    free_board(board1);
}