#include "uls.h"

bool mx_check_device(t_directory **names, t_size *size) {
    for (int i = 0; names[i]; i++) {
        if (S_ISBLK(names[i]->info.st_mode) ||
            S_ISCHR(names[i]->info.st_mode)) {
            return size->is_dev = true;
        }
    }
    
    return size->is_dev = false;
}
