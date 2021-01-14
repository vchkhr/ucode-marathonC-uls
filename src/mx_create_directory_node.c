#include "uls.h"

t_directory *mx_create_directory_node(char *data) {
    t_directory *node = (t_directory *)malloc(sizeof(t_directory));

    node->name = mx_strdup(data);
    node->path = mx_strdup(data);
    node->error = NULL;

    if (lstat(data, &(node->info)) == -1) {
        node->error = mx_strdup(strerror(errno));
    }

    node->open = NULL;
    
    return node;
}
