#include "uls.h"

void mx_sort(t_directory ***list, t_flag *flag) {
	for (int i = 0; i < mx_size_list_arr(*list); i++) {
		for (int j = i + 1; j < mx_size_list_arr(*list); j++) {
            if ((*list)[i]->error != NULL) {
                if (mx_strcmp((*list)[i]->name, (*list)[j]->name) == 1) {
                    mx_swap_list(&((*list)[i]), &((*list)[j]));
                }
            } else if (mx_comparator((*list)[i], (*list)[j], flag) ==
                                     flag->r) {
                mx_swap_list(&((*list)[i]), &((*list)[j]));
            }
		}
	}
}
