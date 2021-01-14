#include "uls.h"

void mx_files_in_directory(t_directory **args, t_amount_of_objects *number,
                           t_directory ***files, t_directory ***directories) {
    if (!S_ISDIR((*args)->info.st_mode)) {
        (*files)[number->files_amount++] = mx_create_file_node((*args));
        (*files)[number->files_amount] = NULL;

        return;
    }
    
    (*directories)[number->directories_amount++] = mx_create_file_node((*args));
    (*directories)[number->directories_amount] = NULL;
}
