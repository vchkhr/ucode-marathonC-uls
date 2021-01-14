#include "uls.h"

void mx_swap_list(t_directory **left, t_directory **right) {
    t_directory *temp = *left;
    
    *left = *right;
    *right = temp;
}
