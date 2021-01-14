#include "uls.h"

bool mx_comparator_level_two(t_directory *left, t_directory *right,
                             t_flag *flag) {
    if (flag->c == 1 && flag->t == 1 && flag->S != 1) {
        if (left->info.st_ctime == right->info.st_ctime) {
            if (left->info.st_ctimespec.tv_nsec ==
                right->info.st_ctimespec.tv_nsec) {
                return mx_strcmp(left->name, right->name);
            }
            if (left->info.st_ctimespec.tv_nsec <
                right->info.st_ctimespec.tv_nsec) {
                return 1;
            }
            
            return 0;
        }
        if (left->info.st_ctime < right->info.st_ctime) {
            return 1;
        }

        return 0;
    }
    else if (flag->t != 1 && flag->S != 1 &&
             mx_strcmp(left->name, right->name) > 0) {
        return 1;
    }
            
    return 0;
}
