#ifndef ULS_H
#define ULS_H

#include "libmx.h"
#include <dirent.h>
#include <dirent.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <string.h>
#include <sys/acl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <time.h>

// Colors
#define LS_COLOR_DEFAULT    "\033[0m"

#define LS_COLOR_RED        "\033[0;31m"
#define LS_COLOR_GREEN      "\033[0;32m"
#define LS_COLOR_YELLOW     "\033[0;33m"
#define LS_COLOR_BLUE       "\033[0;34m"
#define LS_COLOR_MAGENTA    "\033[0;35m"

#define LS_COLOR_RED_BG     "\033[41;30m"
#define LS_COLOR_GREEN_BG   "\033[42;30m"
#define LS_COLOR_YELLOW_BG  "\033[43;34m"
#define LS_COLOR_CYAN_BG    "\033[46;30m"

// Permissions
#define IS_RWXU(mode)       ((mode) & S_IRWXU)
#define IS_RUSR(mode)       ((mode) & S_IRUSR)
#define IS_WUSR(mode)       ((mode) & S_IWUSR)
#define IS_XUSR(mode)       ((mode) & S_IXUSR)

#define IS_RWXG(mode)       ((mode) & S_IRWXG)
#define IS_RGRP(mode)       ((mode) & S_IRGRP)
#define IS_WGRP(mode)       ((mode) & S_IWGRP)
#define IS_XGRP(mode)       ((mode) & S_IXGRP)

#define IS_RWXO(mode)       ((mode) & S_IRWXO)
#define IS_ROTH(mode)       ((mode) & S_IROTH)
#define IS_WOTH(mode)       ((mode) & S_IWOTH)
#define IS_XOTH(mode)       ((mode) & S_IXOTH)

#define IS_RWX(mode)        (IS_RWXU(mode) && IS_RWXG(mode) && IS_RWXO(mode))
#define IS_R(mode)          (IS_RUSR(mode) && IS_RGRP(mode) && IS_ROTH(mode))
#define IS_W(mode)          (IS_WUSR(mode) && IS_WGRP(mode) && IS_WOTH(mode))
#define IS_X(mode)          (IS_XUSR(mode) && IS_XGRP(mode) && IS_XOTH(mode))

// Flag struct
typedef struct s_flag {
    int l;
    int C;
    int x;
    int R;
    int r;
    int t;
    int u;
    int c;
    int S;
    int a;
    int A;
    int force;
    int m;
    int files;
    int G;
    int T;
    int g;
    int o;
    int ex;
}              t_flag;

// Size struct
typedef struct s_size {
    int link;
    int size;
    int group;
    int user;
    bool is_dev;
}              t_size;

// Directory struct
typedef struct s_directory {
    char *name;
    char *path;
    char *error;
    struct stat info;
    struct s_directory **open;
}              t_directory;

// Amount of objects struct
typedef struct s_amount_of_objects {
    int files_amount;
    int directories_amount;
    int errors_amount;
    int index;
}              t_amount_of_objects;

// Main
int main(int, char **);
void mx_parser(int, char **);

// Flag
void mx_add_flags(t_flag **, char);
t_flag *mx_get_flags(char **, int *);
int mx_check_flag_a(char *, t_flag *);
int mx_check_flag_A(char *, t_flag *);

// Stat
bool mx_check_device(t_directory **, t_size *);
char *mx_check_group(t_directory *);
char *mx_check_password(t_directory *);
char mx_get_file_acl(t_directory *);
char mx_get_file_type(t_directory *);
void mx_get_group_name(t_directory *, int);
void mx_get_user_name(t_directory *, int);
char *mx_get_major(t_directory *);
char *mx_get_minor(t_directory *);
char *mx_minor_to_hex(char *);
int mx_max_names_length(t_directory **);
int mx_max_length_of_files_g(t_directory **);
void mx_edit_time(t_directory *, char *, t_flag *);
char **mx_get_name(int, char **, int, int *);

// Directory
void mx_create_directory(t_directory ***, t_directory ***);
void mx_create_files_in_directory(t_directory ***, t_directory ***, t_directory ***, t_directory ***);
t_directory **mx_create_list_directories(char **, int);
t_directory *mx_create_directory_node(char *);
t_directory *mx_create_file_node(t_directory *);
t_directory *mx_create_node_with_name(char *, char *);
void mx_open_directories(t_directory ***, t_flag *);
void mx_open_directory(t_directory ***, t_flag *);
int mx_count_directories(t_directory **, t_flag *);
void mx_count_size(t_size *, t_directory *);
t_directory **mx_get_files(t_directory ***, t_flag *);
t_directory **mx_get_names(int, char **, int);

// Amount
t_amount_of_objects *mx_create_objects_amount();
void mx_files_in_directory(t_directory **, t_amount_of_objects *, t_directory ***, t_directory ***);

// Sort
void mx_sort(t_directory ***, t_flag *);
int mx_size_list_arr(t_directory **);
void mx_swap_list(t_directory **, t_directory **);
bool mx_comparator(t_directory *, t_directory *, t_flag *);
bool mx_comparator_level_one(t_directory *, t_directory *, t_flag *);
bool mx_comparator_level_two(t_directory *, t_directory *, t_flag *);

// Output
void mx_output(t_directory ***, t_flag *);
void mx_output_c(t_directory **);
void mx_output_g(t_directory **, t_flag *);
void mx_output_m(t_directory **, t_flag *);
void mx_output_x(t_directory **);
void mx_output_one(t_directory **, t_flag *);
void mx_output_long(t_directory **, t_flag *, int);
void mx_output_menu(t_directory ***, t_flag *, int);
void mx_output_error(t_directory ***, t_flag *);
void mx_output_error_open(t_directory **, t_flag *);

// Print
void mx_print_all(t_directory *, t_size *, t_flag *);
void mx_print_columns(t_directory **, int, int, int);
void mx_print_columns_c(t_directory **, int, int, int);
void mx_print_columns_g(t_directory **, int, int, int);
void mx_print_columns_x(t_directory **, int, int, int);
void mx_print_names(t_directory **, int, t_flag *);
void mx_print_names_c(t_directory **, int, int);
void mx_print_names_g(t_directory **, int, int, t_flag *);
void mx_print_names_x(t_directory **, int, int);
void mx_print_duo_cases(t_directory *, t_size *);
void mx_print_color_g(t_directory *, t_flag *);
void mx_print_with_g(t_directory *);
void mx_print_row_g(t_directory **, int);
void mx_print_spaces_g(int, int);
void mx_print_link(t_directory *, t_size *);
void mx_print_symblink(t_directory *);
void mx_print_permission(t_directory *);
void mx_print_size(t_directory *, t_size *);
void mx_print_tab(int, int);
void mx_print_spaces(int);
void mx_print_new_line(int *);
void mx_print_usage(t_flag **, char);

// Delete
void mx_delete_directories(t_directory ***);
void mx_delete_files(t_directory ***, t_flag *);
void mx_delete_directories_list(t_directory ***, t_directory **);

#endif
