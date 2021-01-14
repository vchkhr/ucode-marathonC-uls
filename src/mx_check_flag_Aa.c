#include "uls.h"

int mx_check_flag_A(char *name, t_flag *fl) {
    if (fl->A != 1 || mx_strcmp(name, ".") == 0 ||
        mx_strcmp(name, "..") == 0) {
        return 0;
    }

    return 1;
}

int mx_check_flag_a(char *name, t_flag *fl) {
    if (mx_strcmp(name, ".") == 0 || mx_strcmp(name, "..") == 0) {
        if (fl->a != 1) {
            return 0;
        }

        return 1;
    }
    if (name[0] == '.' && fl->a == 1) {
        return 1;
    }

    return 0;
}
