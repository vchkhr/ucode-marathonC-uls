#include "uls.h"

void mx_open_directory(t_directory ***args, t_flag *fl) {
    DIR *directory_pointer;
    struct dirent *ds;
    int count = 0;

    for (int i = 0; (*args)[i] != NULL; i++) {
        count = mx_count_directories(&(*args)[i], fl);

        if (count > 0) {
            (*args)[i]->open = (t_directory **) malloc(sizeof(t_directory *) *
                               (count + 1));

            if ((directory_pointer = opendir((*args)[i]->path)) != NULL) {
                for (count = 0; (ds = readdir(directory_pointer)) != NULL;) {
                    if (ds->d_name[0] != '.' ||
                        mx_check_flag_A(ds->d_name, fl) ||
                        mx_check_flag_a(ds->d_name, fl)) {
                        (*args)[i]->open[count++] = mx_create_node_with_name(
                            ds->d_name, (*args)[i]->path);
                    }
                }

                (*args)[i]->open[count] = NULL;
            }

            closedir(directory_pointer);
        }
    }

    mx_output(args, fl);
}
