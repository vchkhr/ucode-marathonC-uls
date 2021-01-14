#include "uls.h"

char *mx_check_group(t_directory *total) {
    struct group *grp = NULL;
    
    grp = getgrgid(total->info.st_gid);

    if (grp) {
        return mx_strdup(grp->gr_name);
    }

    return mx_itoa(total->info.st_gid);
}
