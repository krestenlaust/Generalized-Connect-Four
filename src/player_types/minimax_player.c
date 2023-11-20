#include "minimax_player.h"

int* clone_board_cells(const struct game_board* board){
    int* copy = malloc(sizeof(int) * board->width * board->height);

    for (int i = 0; i < board->width * board->height; ++i) {
        copy[i] = board->cells[i];
    }

    return copy;
}

float static_evaluation(struct game_board board, struct game_rules rules, game_checker checker, int depth){
    int result = checker(board, rules);

    if (result == NOT_FINISHED){
        // TODO: Implement better evaluation.

        return 0;
    }

    if (result == DRAW){
        return 0;
    }

    if (result == 0){ // Favor winning sooner
        return (1/(float)depth) * 1;
    }else{
        return (1/(float)depth) * -1;
    }
}

float minimax_evaluation(struct game_board board, struct game_rules rules, game_checker checker, int current_turn, int depth, float alpha, float beta){
    float current_evaluation = static_evaluation(board, rules, checker, depth + 1);

    // Game finished or depth reached.
    if (depth == 0 || current_evaluation >= 1 || current_evaluation <= -1){
        return current_evaluation;
    }

    bool maximising = current_turn == 0;

    // Set a value so little that it will always be beaten (normal max is 1 and -1).
    float best_evaluation = maximising ? -2 : 2;

    for (int i = 0; i < board.width; ++i) {
        // Invalid move
        if (find_first_empty_in_column(board, i) == CELL_NON_EXISTENT){
            continue;
        }

        struct game_board new_board = board;
        int* new_cells = clone_board_cells(&board);
        new_board.cells = new_cells;

        put_column(&new_board, i, current_turn);

        float new_evaluation = minimax_evaluation(new_board, rules, checker, current_turn == 0 ? 1 : 0, depth - 1, alpha, beta);
        free(new_cells);

        if (maximising){
            if (new_evaluation > best_evaluation){
                best_evaluation = new_evaluation;
            }

            if (best_evaluation > alpha){
                alpha = best_evaluation;
            }
        }else{
            if (new_evaluation < best_evaluation){
                best_evaluation = new_evaluation;
            }

            if (best_evaluation < beta){
                beta = best_evaluation;
            }
        }

        if (beta <= alpha){
            //break;
        }
    }

    return best_evaluation;
}

struct move{
    int x;
    float eval;
};

int player_agent_minimax_ai(struct game_board board, struct game_rules rules){
    struct move considered_moves[board.width];

    for (int i = 0; i < board.width; ++i) {
        considered_moves[i].x = -1;
    }

    for (int i = 0; i < board.width; ++i) {
        // Invalid move
        if (find_first_empty_in_column(board, i) == CELL_NON_EXISTENT){
            continue;
        }

        struct game_board new_board = board;
        int* new_cells = clone_board_cells(&board);
        new_board.cells = new_cells;

        put_column(&new_board, i, 1);
        float new_evaluation = minimax_evaluation(new_board, rules, game_checker_nearest_slots, 0, 6, -2, 2);
        free(new_cells);

        printf("Move %d, eval %lf\n", i, new_evaluation);
        considered_moves[i].x = i;
        considered_moves[i].eval = new_evaluation;
    }

    float best_eval = 2;
    int best_move = 0;
    for (int i = 0; i < board.width; ++i) {
        if (considered_moves[i].x == -1){
            continue;
        }

        if (considered_moves[i].eval < best_eval){
            best_eval = considered_moves[i].eval;
            best_move = considered_moves[i].x;
        }
    }

    return best_move;
}