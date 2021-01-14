#include "uls.h"

void mx_parser(int argc, char *argv[]) {
    int count = 1;
    t_flag *fl = mx_get_flags(argv, &count);
    t_directory **args = mx_get_names(argc, argv, count);
    int ex = 0;

    if (args) {
        mx_open_directories(&args, fl);
    }
    if (fl->ex == 1) {
        ex = 1;
    }

    free(fl);
    fl = NULL;
    
    exit(ex);
}
