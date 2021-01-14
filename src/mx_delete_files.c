#include "uls.h"

void mx_delete_files(t_directory ***args, t_flag *fl) {
    t_directory **directories = NULL;
    int new_directory = 0;

    mx_create_directory(&directories, args);

    for (int i = 0; (*args)[i] != NULL; i++) {
        if ((*args)[i]->error == NULL) {
            if (S_ISDIR((*args)[i]->info.st_mode) &&
                mx_strcmp((*args)[i]->name, ".") != 0 &&
                mx_strcmp((*args)[i]->name, "..") != 0) {
                directories[new_directory++] = mx_create_file_node((*args)[i]);
                directories[new_directory] = NULL;
            }
        }
    }

    fl->files = 1;
    mx_delete_directories_list(args, directories);
}
