#include "player_types.h"
#include <stdio.h>

/**
 * Returns a random valid move.
 * @param board The current state of the game.
 * @param rules The rules of the game.
 * @return Returns (zero-indexed) column to put token in, -1 if there's no valid moves.
 */
int player_agent_random_ai(struct game_board board, struct game_rules rules){
    // SRand is called in play_game.

    const int random_move = rand() % board.width;
    int move = random_move;

    while (find_first_empty_in_column(board, move) == CELL_NON_EXISTENT){
        move = move + 1 % board.width;

        // Detect when no valid moves are available.
        if (move == random_move){
            move = -1;
            break;
        }
    }

    return move;
}

int player_agent_console(struct game_board board, struct game_rules rules){
    printf("Input a number between 1 and %d> ", board.width);

    int move;

    do {
        int move_one_indexed;

        if (!scanf("%d", &move_one_indexed)){
            continue;
        }

        move = move_one_indexed - 1;
    } while (move < 0 || move >= board.width);

    return move;
}