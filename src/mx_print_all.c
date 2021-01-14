#include "uls.h"

void mx_print_all(t_directory *print, t_size *size, t_flag *fl) {
    time_t *chtime = &print->info.st_ctime;
    time_t *atime = &print->info.st_atime;
    time_t *ttime = &print->info.st_mtime;

    mx_print_permission(print);
    mx_print_link(print, size);

    if ((fl->l == 1 && fl->g == 0) || (fl->o == 1 && fl->g == 0)) {
        mx_get_user_name(print, size->user);
    }
    if ((fl->l == 1 && fl->o == 0) || (fl->g == 1 && fl->o == 0)) {
        mx_get_group_name(print, size->group);
    }

    mx_print_size(print, size);

    if (fl->u == 1) {
        ttime = atime;
    }
    if (fl->c == 1) {
        ttime = chtime;
    }

    mx_edit_time(print, ctime(ttime), fl);
    mx_print_color_g(print, fl);
    mx_printchar('\n');
}
