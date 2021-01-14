#include "uls.h"

int mx_size_list_arr(t_directory **list) {
	int size = 0;

	for (; list[size];) {
		size++;
	}
	
	return size;
}
