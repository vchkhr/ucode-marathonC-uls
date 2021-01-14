#include "uls.h"

void mx_print_names(t_directory **names, int wincol, t_flag *fl) {
    int len = 0;
    int next_length = 0;

    for (int i = 0; names[i]; i++) {
        if (fl->G == 1) {
            mx_print_with_g(names[i]);
        }
        else if (fl->G != 1) {
            mx_printstr(names[i]->name);
        }

        len += mx_strlen(names[i]->name) + 2;

        if (names[i + 1]) {
            mx_printstr(", ");

            if (names[i + 2]) {
                next_length = 3;
            }
            else {
                next_length = 1;
            }
            if (len + next_length + mx_strlen(names[i + 1]->name) > wincol) {
                mx_print_new_line(&len);
            }
        }
    }
    
    mx_printchar('\n');
}
