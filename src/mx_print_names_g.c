#include "uls.h"

void mx_print_names_g(t_directory **names, int maxlen, int wincol, t_flag *fl) {
    int rows;
    int cols;
    int num = 0;

    if ((wincol / maxlen) != 0) {
        cols = wincol / maxlen;
    }
    else  {
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
        if (fl->x == 0) {
            mx_print_columns_c(names, rows, num, maxlen);
        }
        else {
            mx_print_columns_g(names, rows, cols, maxlen);
        }
    }
    else {
        mx_print_row_g(names, maxlen);
    }

    mx_printchar('\n');
}
