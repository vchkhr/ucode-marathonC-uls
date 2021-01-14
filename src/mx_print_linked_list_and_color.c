#include "uls.h"

void mx_print_color_g(t_directory *print, t_flag *fl) {
    if (fl->G == 1) {
        mx_print_with_g(print);
    }
    else {
        mx_printstr(print->name);
    }
    if (S_ISLNK(print->info.st_mode)) {
        mx_print_symblink(print);
    }
}
