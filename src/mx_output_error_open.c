#include "uls.h"

void mx_output_error_open(t_directory **args, t_flag *fl) {
    if ((*args)->open != NULL) {
        mx_output_menu(&(*args)->open, fl, 1);

        if (fl->R == 1) {
            fl->files = 1;
            mx_delete_files(&(*args)->open, fl);
            
            if ((*args)->open) {
                mx_printchar('\n');
                mx_open_directories(&(*args)->open, fl);
            }
        }
    }
    else if ((*args)->error != NULL) {
        mx_printerr("uls: ");
        mx_printerr((*args)->path);
        mx_printerr(": ");
        mx_printerr((*args)->error);
        mx_printerr("\n");
    }
}
