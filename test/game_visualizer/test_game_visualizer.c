#include <assert.h>
#include "game_visualizer.h"

void test_digit_to_char(void);

int main(void) {
    test_digit_to_char();
}

void test_digit_to_char(void){
    int zero = 0;
    int nine = 9;

    char zero_digit = digit_to_char(zero);
    char nine_digit = digit_to_char(nine);

    assert(zero_digit == '0');
    assert(nine_digit == '9');
}