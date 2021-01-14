#include "uls.h"

char *mx_get_minor(t_directory *print) {
    int minor_num = (int)(print->info.st_rdev & 0xffffff);

    if (minor_num > 255) {
        return mx_minor_to_hex(mx_nbr_to_hex(minor_num));
    }
    
    return mx_itoa(minor_num);
}
