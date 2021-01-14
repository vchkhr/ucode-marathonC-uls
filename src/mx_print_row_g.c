#include "uls.h"

void mx_print_row_g(t_directory **names, int maxlen) {
    for (int i = 0; names[i]; i++) {
        mx_print_with_g(names[i]);

        if (names[i + 1]) {
            mx_print_spaces_g(mx_strlen(names[i]->name), maxlen);
        }
    }
}
