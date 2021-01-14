#include "uls.h"

int mx_count_directories(t_directory **arg, t_flag *fl) {
    int count = 0;
    t_directory *arguments = *arg;
    DIR *directory_pointer;
    struct dirent *d;

    if (S_ISDIR(arguments->info.st_mode) || S_ISLNK(arguments->info.st_mode)) {
        if ((directory_pointer = opendir(arguments->path)) != NULL) {
            for (; (d = readdir(directory_pointer)) != NULL;) {
                if (d->d_name[0] != '.' || mx_check_flag_A(d->d_name, fl) ||
                    mx_check_flag_a(d->d_name, fl)) {
                    count++;
                }
            }

            closedir(directory_pointer);
        }
        else {
            (*arg)->error = mx_strdup(strerror(errno));
            fl->ex = 1;

            return -1;
        }
    }
    
    return count;
}
