#include "uls.h"

void mx_output(t_directory ***args, t_flag *fl) {
    if (*args) {
        for (int i = 0; (*args)[i] != NULL; i++) {
            if (fl->files == 1) {
                if ((*args)[i]->path[0] == '/' && (*args)[i]->path[1] == '/') {
                    mx_printstr(&(*args)[i]->path[1]);
                }
                else {
                    mx_printstr((*args)[i]->path);
                }

                mx_printchar(':');
				mx_printchar('\n');
            }

            mx_output_error_open(&(*args)[i], fl);

            if (fl->files == 1 && (*args)[i+1]) {
                mx_printchar('\n');
            }
        }
        
        mx_delete_directories(args);
    }
}
