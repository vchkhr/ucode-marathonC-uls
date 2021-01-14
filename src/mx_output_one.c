#include "uls.h"

void mx_output_one(t_directory **names, t_flag *fl) {
    for (int i = 0; names[i]; i++) {
        if (fl->G != 1) {
            mx_printstr(names[i]->name);
        }
        else {
            mx_print_with_g(names[i]);
        }
        
        mx_printchar('\n');
    }
}
