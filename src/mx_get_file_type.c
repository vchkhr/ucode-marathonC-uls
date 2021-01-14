#include "uls.h"

char mx_get_file_type(t_directory *print) {
    if (S_ISLNK(print->info.st_mode)) {
        return 'l';
    }
    if (S_ISDIR(print->info.st_mode)) {
        return 'd';
    }
    if (S_ISCHR(print->info.st_mode)) {
        return 'c';
    }
    if (S_ISBLK(print->info.st_mode)) {
        return 'b';
    }
    if (S_ISFIFO(print->info.st_mode)) {
        return 'p';
    }
    if (S_ISSOCK(print->info.st_mode)) {
        return 's';
    }
    if (S_ISWHT(print->info.st_mode)) {
        return 'w';
    }

    return '-';
}
