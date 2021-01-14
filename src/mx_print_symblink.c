#include "uls.h"

void mx_print_symblink(t_directory *print) {
    char *buffer = NULL;
    ssize_t bytes = 0;
    ssize_t size_buffer = 0;

    size_buffer = print->info.st_size == 0 ? 100 : print->info.st_size + 1;
    buffer = mx_strnew(size_buffer);
    bytes = readlink(print->path, buffer, size_buffer);

    mx_printstr(" -> ");

    if (bytes >= 0) {
        mx_printstr(buffer);
    }
    
    mx_strdel(&buffer);
}
