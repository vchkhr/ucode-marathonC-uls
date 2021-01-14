#include "uls.h"

void mx_get_user_name(t_directory *print, int user) {
    struct passwd *pw = getpwuid(print->info.st_uid);
    int counter = 0;
    char *name = NULL;

    if (pw) {
        name = mx_strdup(pw->pw_name);
    }
    else {
        name = mx_itoa(print->info.st_uid);
    }
    if (mx_strlen(name) == user) {
       mx_printstr(name);
    }
    else if (mx_strlen(name) < user) {
        counter = mx_strlen(name);
        mx_printstr(name);

        for (; counter != user; counter++) {
            mx_printchar(' ');
        }
    }

    for (int i = 0; i < 2; i++) {
        mx_printchar(' ');
    }
    
    free(name);
}
