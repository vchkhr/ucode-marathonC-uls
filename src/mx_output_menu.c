#include "uls.h"

void mx_output_menu(t_directory ***names, t_flag *fl, int flag) {
    if (**names != NULL) {
        mx_sort(&(*names), fl);

        if (fl->l) {
            mx_output_long(*names, fl, flag);
        }
        if (fl->C == 1 && !fl->G) {
            mx_output_c(*names);
        }
        if (fl->x == 1 && !fl->G) {
            mx_output_x(*names);
        }
        if (fl->m == 1) {
            mx_output_m(*names, fl);
        }
        if (fl->force == 1) {
            mx_output_one(*names, fl);
        }
        if (fl->G == 1 && fl->m != 1 && fl->l != 1 && fl->force != 1) {
            mx_output_g(*names, fl);
        }
        if (fl->l != 1 && fl->C != 1 && fl->x != 1 && fl->m != 1 && fl->force != 1 && !fl->G && !fl->g && !fl->o && isatty(1)) {
            mx_output_c(*names);
        }
        if (!isatty(1) && fl->C != 1 && fl->x != 1 && fl->m != 1 && fl->l != 1 && fl->g != 1 && fl->o != 1 && fl->force != 1) {
            mx_output_one(*names, fl);
        }
    }
}
