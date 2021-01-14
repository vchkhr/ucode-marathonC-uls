#include "uls.h"

bool mx_comparator(t_directory *left, t_directory *right, t_flag *flag) {
    if (flag->S == 1) {
        if (left->info.st_size < right->info.st_size) {
            return 1;
        }
        if (left->info.st_size == right->info.st_size) {
            return mx_strcmp(left->name, right->name);
        }
    }
    else if (flag->t == 1 && flag->c != 1 && flag->u != 1) {
        if (left->info.st_mtime == right->info.st_mtime) {
            if (left->info.st_mtimespec.tv_nsec ==
                right->info.st_mtimespec.tv_nsec) {
                return mx_strcmp(left->name, right->name);
            }
            if (left->info.st_mtimespec.tv_nsec <
                right->info.st_mtimespec.tv_nsec) {
                return 1;
            }
            
            return 0;
        }
        if (left->info.st_mtime < right->info.st_mtime) {
            return 1;
        }

        return 0;
    }

    return mx_comparator_level_one(left, right, flag);
}
