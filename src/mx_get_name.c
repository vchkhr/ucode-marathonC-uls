#include "uls.h"

char **mx_get_name(int argc, char **argv, int i, int *count) {
    char **name = NULL;

    if (i == argc) {
        *count = 2;
        
        name = malloc(2 * sizeof(char *));
        name[0] = mx_strdup(".");
        name[1] = NULL;
    }
    else {
        int j = i;
        
        for (; argv[j];) {
            j++;
        }

        name = malloc((j - i + 1) * sizeof(char *));

        for (j = 0; argv[i]; i++, j++) {
            name[j] = mx_strdup(argv[i]);
        }

        name[j] = NULL;
        *count = j + 1;
    }
    
    return name;
}
