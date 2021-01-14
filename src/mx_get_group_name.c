#include "uls.h"

void mx_get_group_name(t_directory *print, int group) {
    struct group *grp = getgrgid(print->info.st_gid);
    int counter = 0;
    char *name = NULL;

    if (grp) {
        name = mx_strdup(grp->gr_name);
    }
    else {
        name = mx_itoa(print->info.st_gid);
    }
    if (mx_strlen(name) == group) {
        mx_printstr(name);
    }
    else if (mx_strlen(name) < group) {
        counter = mx_strlen(name);
        mx_printstr(name);

        for (; counter != group; counter++) {
            mx_printchar(' ');
        }
    }
    
    for (int i = 0; i < 2; i++) {
        mx_printchar(' ');
    }

    free(name);
}
