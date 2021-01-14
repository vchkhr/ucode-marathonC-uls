#include "uls.h"

bool mx_comparator_level_one(t_directory *left, t_directory *right,
                             t_flag *flag) {
    if (flag->u == 1 && flag->t == 1 && flag->S != 1) {
        if (left->info.st_atime == right->info.st_atime) {
            if (left->info.st_atimespec.tv_nsec ==
                right->info.st_atimespec.tv_nsec) {
                return mx_strcmp(left->name, right->name);
            }
            if (left->info.st_atimespec.tv_nsec <
                right->info.st_atimespec.tv_nsec) {
                return 1;
            }

            return 0;
        }
        if (left->info.st_atime < right->info.st_atime) {
            return 1;
        }

        return 0;
    }
    else {
        return mx_comparator_level_two(left, right, flag);
    }
}
