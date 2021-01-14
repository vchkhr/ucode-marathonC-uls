#include "uls.h"

t_directory **mx_get_files(t_directory ***args, t_flag *fl) {
    t_directory **files = NULL;
    t_directory **directories = NULL;
    t_directory **errors = NULL;
    t_amount_of_objects *amount = mx_create_objects_amount();

    mx_create_files_in_directory(&files, &directories, &errors, args);

    for (; (*args)[amount->index] != NULL; amount->index++) {
        if ((*args)[amount->index]->error == NULL) {
            mx_files_in_directory(&(*args)[amount->index], amount, &files,
                                  &directories);
        }
        else {
            errors[amount->errors_amount++] = mx_create_file_node((*args)[amount->index]);
            errors[amount->errors_amount] = NULL;
        }
    }

    if (amount->directories_amount > 1) {
        fl->files = 1;
    }

    mx_delete_directories_list(args, directories);
    mx_output_error(&errors, fl);
    free(amount);
    
    return files;
}
