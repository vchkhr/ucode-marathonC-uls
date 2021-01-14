#include "uls.h"

void mx_open_directories(t_directory ***args, t_flag *fl) {
    t_directory **files = mx_get_files(&(*args), fl);

	if (files) {
		mx_output_menu(&files, fl, 0);
        
		if (*args) {
			mx_printchar('\n');
        }

		fl->files = 1;
        mx_delete_directories(&files);
	}
    if (*args) {
        mx_open_directory(&(*args), fl);
    }
}
