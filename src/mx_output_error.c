#include "uls.h"

void mx_output_error(t_directory ***error, t_flag *fl) {
    if (error && *error && **error) {
        mx_sort(error, fl);

        fl->files = 1;
        fl->ex = 1;

        for (int i = 0; (*error)[i]; i++) {
            mx_printerr("uls: ");
            mx_printerr((*error)[i]->name);
            mx_printerr(": ");
            mx_printerr((*error)[i]->error);
            mx_printerr("\n");

            mx_strdel(&(*error)[i]->name);
            mx_strdel(&(*error)[i]->path);
            mx_strdel(&(*error)[i]->error);

            free((*error)[i]);
            (*error)[i] = NULL;
        }

        free(*error);
        *error = NULL;
    }
}
