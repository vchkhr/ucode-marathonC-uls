#include "uls.h"

void mx_print_with_g(t_directory *args) {
    if (S_ISDIR(args->info.st_mode)) {
        if (IS_WOTH(args->info.st_mode)) {
            mx_printstr(LS_COLOR_GREEN_BG);
        }
        else {
            mx_printstr(LS_COLOR_BLUE);
        }
    }
    else if (S_ISLNK(args->info.st_mode)) {
        mx_printstr(LS_COLOR_MAGENTA);
    }
    else if (S_ISSOCK(args->info.st_mode)) {
        mx_printstr(LS_COLOR_GREEN);
    }
    else if (S_ISFIFO(args->info.st_mode)) {
        mx_printstr(LS_COLOR_YELLOW);
    }
    else if (S_ISBLK(args->info.st_mode)) {
        mx_printstr(LS_COLOR_CYAN_BG);
    }
    else if (S_ISCHR(args->info.st_mode)) {
        mx_printstr(LS_COLOR_YELLOW_BG);
    }
    else if (S_ISWHT(args->info.st_mode)) {
        mx_printstr(LS_COLOR_RED_BG);
    }
    else if (IS_R(args->info.st_mode) && IS_X(args->info.st_mode)) {
        mx_printstr(LS_COLOR_RED);
    }

    mx_printstr(args->name);
    mx_printstr(LS_COLOR_DEFAULT);
}
