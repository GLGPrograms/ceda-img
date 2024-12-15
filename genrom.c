#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[]) {
    for (size_t i = 0; i < 256; ++i) {
        for (size_t r = 0; r < 4; ++r) {
            uint8_t g = 0;
            uint8_t bp = i >> (6 - r * 2) & 0x3;
            switch (bp) {
                case 0:
                    g = 0x00;
                    break;
                case 1:
                    g = 0x0f;
                    break;
                case 2:
                    g = 0xf0;
                    break;
                case 3:
                    g = 0xff;
                    break;
                default:
                    return 1;
            }
            putc(g, stdout);
            putc(g, stdout);
            putc(g, stdout);
            putc(g, stdout);
        }
    }
    return 0;
}
