#include "uls.h"

t_directory *mx_create_node_with_name(char *name, char *path) {
    t_directory *node = (t_directory *) malloc(sizeof(t_directory));

    node->name = mx_strdup(name);
    node->path = mx_strdup(path);
    node->path = mx_strjoin(node->path, "/");
    node->path = mx_strjoin(node->path, name);
    node->error = NULL;

    if (lstat(node->path, &(node->info)) == -1) {
        node->error = mx_strdup(strerror(errno));
    }

    node->open = NULL;
    
    return node;
}
