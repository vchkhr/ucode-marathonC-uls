#include "uls.h"

void mx_add_flags(t_flag **fl, char flag) {
    if (flag == 'T') {
        (*fl)->T = 1;
    }
    else if (flag == 'G' && isatty(1)) {
        (*fl)->G = 1;
    }
    else if (flag == 'c') {
        (*fl)->u = 0;
        (*fl)->c = 1;
    }
    else if (flag == 't') {
        (*fl)->t = 1;
    }
    else if (flag == 'u') {
        (*fl)->u = 1;
        (*fl)->c = 0;
    }
    else if (flag == 'S') {
        (*fl)->S = 1;
    }
    else if (flag == 'r' && (*fl)->r != -1) {
        (*fl)->r = 0;
    }
    else if (flag == 'G' && !isatty(1)) {
        (*fl)->G = 0;
    }
    else if (flag == 'R') {
        (*fl)->R = 1;
    }
    else if (flag == 'a') {
        (*fl)->a = 1;
    }
    else if (flag == 'A') {
        (*fl)->A = 1;
    }
    else if (flag == 'g') {
        (*fl)->g = 1;
        (*fl)->l = 1;
    }
    else if (flag == 'o') {
        (*fl)->o = 1;
        (*fl)->l = 1;
    }
    else if (flag == 'l') {
        (*fl)->l = 1;
    }
    else if (flag == 'C') {
        (*fl)->C = 1;
    }
    else if (flag == '1') {
        (*fl)->force = 1;
    }
    else if (flag == 'x') {
        (*fl)->x = 1;
    }
    else if (flag == 'm') {
        (*fl)->m = 1;
    }
    else {
        mx_print_usage(fl, flag);
    }
}
