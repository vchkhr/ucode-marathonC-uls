#include "uls.h"

void mx_print_names_c(t_directory **names, int maxlen, int wincol) {
    int rows;
    int cols;
    int num = 0;

    if ((wincol / maxlen) != 0) {
        cols = wincol / maxlen;
    }
    else {
        cols = 1;
    }

    for (; names[num];) {
        num++;
    }

    if (maxlen * cols > wincol && cols != 1) {
        cols--;
    }
    if (num * maxlen > wincol) {
        rows = num / cols;

        if (rows == 0 || num % cols != 0) {
            rows += 1;
        }

        mx_print_columns(names, rows, num, maxlen);
    } else {
        for (int i = 0; names[i]; i++) {
            mx_printstr(names[i]->name);

            if (names[i + 1]) {
                mx_print_tab(mx_strlen(names[i]->name), maxlen);
            }
        }
    }

    mx_printchar('\n');
}
