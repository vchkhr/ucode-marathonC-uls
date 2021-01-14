#include "uls.h"

void mx_output_x(t_directory **names) {
    if (!names) {
        return;
    }

    struct winsize win;
    int max_length = mx_max_names_length(names);

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    
    if (isatty(1)) {
        mx_print_names_x(names, max_length, win.ws_col);
    }
    else {
        mx_print_names_x(names, max_length, 80);
    }
}
