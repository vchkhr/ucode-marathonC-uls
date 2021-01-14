#include "uls.h"

t_directory **mx_get_names(int argc, char **argv, int i) {
    int count = 0;
    char **name = mx_get_name(argc, argv, i, &count);
    t_directory **args = mx_create_list_directories(name, count);

    mx_del_strarr(&name);

    return args;
}
