#include "uls.h"

char *mx_check_password(t_directory *total) {
    struct passwd *pw = NULL;

    pw = getpwuid(total->info.st_uid);

    if (pw) {
        return mx_strdup(pw->pw_name);
    }
    
    return mx_itoa(total->info.st_uid);
}
