#include "uls.h"

void mx_delete_directories(t_directory ***args) {
    t_directory **del_arr = *args;

    for (int i = 0; del_arr[i]!= NULL; i++) {
        mx_strdel(&del_arr[i]->name);
        mx_strdel(&del_arr[i]->path);

        if (del_arr[i]->error) {
            mx_strdel(&del_arr[i]->error);
        }
        if (del_arr[i]->open != NULL) {
            mx_delete_directories(&del_arr[i]->open);
        }

        free(del_arr[i]);
        del_arr[i] = NULL;
    }

    free(*args);
    *args = NULL;
}
