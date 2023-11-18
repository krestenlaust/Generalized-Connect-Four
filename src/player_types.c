#include "player_types.h"

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

    while (!put_column(board, move, 1)){
        move = move + 1 % board.width;

        // Detect when no valid moves are available.
        if (move == random_move){
            move = -1;
            break;
        }
    }

    return move;
}