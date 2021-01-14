#include "uls.h"

void mx_output_g(t_directory **names, t_flag *fl) {
    if (!names) {
        return;
    }

    struct winsize win;
    int max_length = mx_max_length_of_files_g(names);

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);

    mx_print_names_g(names, max_length, win.ws_col, fl);
}
