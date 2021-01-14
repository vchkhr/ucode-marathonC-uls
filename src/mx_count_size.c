#include "uls.h"

void mx_count_size(t_size *size, t_directory *total) {
    char *name_grp = mx_check_group(total);
    char *name_pw = mx_check_password(total);

    if (size->link < total->info.st_nlink) {
        size->link = total->info.st_nlink;
    }
    if (size->size < total->info.st_size) {
        size->size = total->info.st_size;
    }
    if (size->group < mx_strlen(name_grp)) {
        size->group = mx_strlen(name_grp);
    }
    if (size->user < mx_strlen(name_pw)) {
        size->user = mx_strlen(name_pw);
    }
    
    free(name_grp);
    free(name_pw);
}
