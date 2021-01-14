#include "uls.h"

t_directory *mx_create_file_node(t_directory *arg) {
    t_directory *node = (t_directory *)malloc(sizeof (t_directory));

    node->name = mx_strdup(arg->name);
    node->path = mx_strdup(arg->path);
    node->error = NULL;

    if (arg->error != NULL) {
        node->error = mx_strdup(arg->error);
    }

    lstat(node->path, &(node->info));

    if (arg->open != NULL) {
        node->open = arg->open;
    }
    else {
        node->open = NULL;
    }
    
    return node;
}
