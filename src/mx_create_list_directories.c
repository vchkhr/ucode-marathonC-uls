#include "uls.h"

t_directory **mx_create_list_directories(char **name, int count) {
    t_directory **new = malloc(count * sizeof(t_directory *));
    int i = 0;

    for (i = 0; name[i]; i++) {
        new[i] = mx_create_directory_node(name[i]);
    }

    new[i] = NULL;
    
    return new;
}
