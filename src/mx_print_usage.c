#include "uls.h"

void mx_print_usage(t_flag **fl, char flag) {
    mx_printerr("uls: illegal option -- ");
    write(2, &flag, 1);
    mx_printerr("\n");
    mx_printerr("usage: uls [-ACGRSTacfglmortux1] [file ...]\n");

    free(*fl);
    fl = NULL;
    
    exit(1);
}
