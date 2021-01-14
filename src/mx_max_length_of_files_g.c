#include "uls.h"

int mx_max_length_of_files_g(t_directory **names) {
    int max = 0;
    int temp = 0;

    for (int i = 0; names[i]; i++) {
        temp = mx_strlen(names[i]->name);

        if (temp > max) {
            max = temp;
        }
    }

    return max++;
}
