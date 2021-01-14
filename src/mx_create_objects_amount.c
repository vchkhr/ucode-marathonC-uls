#include "uls.h"

t_amount_of_objects *mx_create_objects_amount() {
    t_amount_of_objects *amount = malloc(sizeof (t_amount_of_objects));

    amount->directories_amount = 0;
    amount->errors_amount = 0;
    amount->files_amount = 0;
    amount->index = 0;
    
    return amount;
}
