#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define TEXT_COLS 80
#define TEXT_ROWS 25
#define GRAPH_PIX_COLS (TEXT_COLS * 2)
#define GRAPH_PIX_ROWS (TEXT_ROWS * 4)

int main(int argc, char* argv[]) {
    static uint8_t buffer[TEXT_ROWS * TEXT_COLS];

    // you never know when your BSS fails
    memset(buffer, 0, sizeof(buffer));


    for (size_t row = 0; row < GRAPH_PIX_ROWS; ++row) {
        const size_t text_row = row / 4;
        size_t text_col = 0;
        for (size_t col = 0; col < GRAPH_PIX_COLS / 8; ++col) {
            int ret = getc(stdin);
            if (ret == -1)
                return 1;
            uint8_t c = (uint8_t)(ret & 0xff);

            for (size_t i = 0; i < 4; ++i) {
                buffer[text_row * TEXT_COLS + text_col + i] |= ((c >> (6 - i * 2)) & 0x3) << (2 * (3 - row % 4));
            }
            text_col += 4;
        }
    }
    for (size_t i = 0; i < TEXT_ROWS * TEXT_COLS; ++i) {
        putc(buffer[i], stdout);
    }
    return 0;
}
