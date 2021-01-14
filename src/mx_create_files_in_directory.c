#include "uls.h"

void mx_create_files_in_directory(t_directory ***files,
                                  t_directory ***directories,
                                  t_directory ***errors, t_directory ***args) {
    int size = 0;
    int new_directory = 0;
    int new_error = 0;

    for (int i = 0; (*args)[i] != NULL; i++) {
        if ((*args)[i]->error == NULL) {
            if (!S_ISDIR((*args)[i]->info.st_mode) ) {
                size++;
            } else
                new_directory++;
        } else {
            new_error++;
        }
    }

    if (size > 0) {
        *files = malloc((size + 1) * sizeof(t_directory *));
    }
    if (new_directory > 0) {
        *directories = malloc((new_directory + 1) * sizeof(t_directory *));
    }
    if (new_error > 0) {
        *errors = malloc((new_error + 1) * sizeof(t_directory *));
    }
}
