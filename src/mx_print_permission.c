#include "uls.h"

void mx_print_permission(t_directory *print) {
    char chmod[12];
    
    chmod[0] = mx_get_file_type(print);
    chmod[1] = IS_RUSR(print->info.st_mode) ? 'r' : '-';
    chmod[2] = IS_WUSR(print->info.st_mode) ? 'w' : '-';
    chmod[3] = IS_XUSR(print->info.st_mode) ? 'x' : '-';
    chmod[4] = IS_RGRP(print->info.st_mode) ? 'r' : '-';
    chmod[5] = IS_WGRP(print->info.st_mode) ? 'w' : '-';
    chmod[6] = IS_XGRP(print->info.st_mode) ? 'x' : '-';
    chmod[7] = IS_ROTH(print->info.st_mode) ? 'r' : '-';
    chmod[8] = IS_WOTH(print->info.st_mode) ? 'w' : '-';
    chmod[9] = IS_XOTH(print->info.st_mode) ? 'x' : '-';
    chmod[10] = mx_get_file_acl(print);
    chmod[11] = '\0';

    if (S_ISUID & print->info.st_mode) {
        if (chmod[3] == '-') {
            chmod[3] = 'S';
        }
        else {
            chmod[3] = 's';
        }
    }
    if (S_ISGID & print->info.st_mode) {
        if (chmod[6] == '-') {
            chmod[6] = 'S';
        }
        else {
            chmod[6] = 's';
        }
    }
    if (S_ISVTX & print->info.st_mode) {
        if (chmod[9] == '-') {
            chmod[9] = 'T';
        }
        else {
            chmod[9] = 't';
        }
    }

    mx_printstr(chmod);
    mx_printchar(' ');
}
