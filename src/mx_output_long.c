#include "uls.h"

void mx_output_long(t_directory **names, t_flag *fl, int flag) {
    t_size *size = malloc(sizeof(t_size));
    int size_block = 0;
    int i = 0;

    size->link = 0;
    size->size = 0;
    size->group = 0;
    size->user = 0;

    for (i = 0; names[i]; i++) {
        size_block += names[i]->info.st_blocks;

        mx_count_size(size, names[i]);
    }

    if (flag == 1) {
        mx_printstr("total ");
        mx_printint(size_block);
        mx_printchar('\n');
    }

    mx_check_device(names, size);

    for (i = 0; names[i]; i++) {
        mx_print_all(names[i], size, fl);
    }

    free(size);
}
