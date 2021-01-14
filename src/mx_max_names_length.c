#include "uls.h"

int mx_max_names_length(t_directory **names) {
    int max = 0;
    int temp = 0;

    for (int i = 0; names[i]; i++) {
        temp = mx_strlen(names[i]->name);

        if (temp > max) {
            max = temp;
        }
    }

    if (max % 8 == 0) {
        max += 8;
    }
    else {
        max = 8 - (max % 8) + max;
    }
    
    return max;
}
