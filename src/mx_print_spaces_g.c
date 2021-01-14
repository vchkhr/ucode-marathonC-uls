#include "uls.h"

void mx_print_spaces_g(int len, int maxlen) {
    for (int i = 0; i < maxlen - len; i++) {
        mx_printchar(' ');
    }
}
