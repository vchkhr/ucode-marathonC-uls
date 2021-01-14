#include "uls.h"

void mx_output_m(t_directory **names, t_flag *fl) {
    if (!names) {
        return;
    }

    struct winsize win;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);

    if (isatty(1)) {
        mx_print_names(names, win.ws_col, fl);
    }
    else {
        mx_print_names(names, 80, fl);
    }
}
