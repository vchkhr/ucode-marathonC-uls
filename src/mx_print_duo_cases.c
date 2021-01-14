#include "uls.h"

void mx_print_duo_cases(t_directory *print, t_size *size) {
    char *major = mx_get_major(print);
    char *minor = mx_get_minor(print);
    
    if (size->is_dev == true)
        if (S_ISBLK(print->info.st_mode) || S_ISCHR(print->info.st_mode)) {
            mx_print_spaces(2 - mx_strlen(major));
            mx_printstr(major);
            mx_printchar(',');
            mx_printchar(' ');
            mx_print_spaces(2 - mx_strlen(minor));
            mx_printstr(minor);
        }
        else {
            for (int i = 0; i < 7; i++) {
                mx_printchar(' ');
            }

            mx_printint(print->info.st_size);
        }
    else {
       mx_printint(print->info.st_size); 
    }
    
    free(major);
    free(minor);
}
