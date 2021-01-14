#include "uls.h"

void mx_print_columns_g(t_directory **names, int rows, int cols, int maxlen) {
    int j = 0;
    int temp_columns = cols;

    for (int i = 0; i < rows; i++, cols += temp_columns) {
        for (; names[j] && j < cols; j++) {
            mx_print_with_g(names[j]);

            if (names[j + 1] && (j != cols - 1)) {
                mx_print_spaces_g(mx_strlen(names[j]->name), maxlen);
            }
        }

        if (i != rows - 1) {
            mx_printchar('\n');
        }
    }
}
