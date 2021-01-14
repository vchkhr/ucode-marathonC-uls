#include "uls.h"

t_flag *mx_get_flags(char *argv[], int *i) {
    t_flag *fl = malloc(sizeof(t_flag));

    fl->r = 1;

    for (; argv[(*i)]; (*i)++) {
        if (argv[(*i)][0] == '-') {
            if (argv[(*i)][1] == '-') {
                (*i)++;

                break;
            }
            if (argv[(*i)][1] == '\0') {
                break;
            }

            for (int j = 1; argv[(*i)][j]; j++) {
                mx_add_flags(&fl, argv[(*i)][j]);
            }
        }
        else {
            break;
        }
    }

    return fl;
}
