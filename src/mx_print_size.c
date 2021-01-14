#include "uls.h"

void mx_print_size(t_directory *print, t_size *size) {
    char *result = mx_itoa(print->info.st_size);
    char *result_size = mx_itoa(size->size);
    int counter = 0;

    if (mx_strlen(result) == mx_strlen(result_size)) {
        mx_print_duo_cases(print, size);
    }
    else if (mx_strlen(result) < mx_strlen(result_size)) {
        counter = mx_strlen(result);

        for (; counter != mx_strlen(result_size); counter++) {
            mx_printchar(' ');
        }

        mx_print_duo_cases(print, size);
    }

    mx_printchar(' ');

    free(result);
    free(result_size);
}
