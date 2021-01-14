#include "uls.h"

void mx_create_directory(t_directory ***directories, t_directory ***args) {
    int new_directory = 0;

    for (int i = 0; (*args)[i] != NULL; i++) {
        if ((*args)[i]->error == NULL) {
            if (S_ISDIR((*args)[i]->info.st_mode) &&
                mx_strcmp((*args)[i]->name, ".") != 0 &&
                mx_strcmp((*args)[i]->name, "..") != 0) {
                new_directory++;
            }
        }
    }

    if (new_directory > 0) {
        *directories = malloc((new_directory + 1) * sizeof(t_directory *));
    }
}
