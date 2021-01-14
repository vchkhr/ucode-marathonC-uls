#include "uls.h"

char mx_get_file_acl(t_directory *print) {
    if (listxattr(print->path, NULL, 0, XATTR_NOFOLLOW) > 0) {
        return ('@');
    }
    if (acl_get_file(print->path, ACL_TYPE_EXTENDED)) {
        return ('+');
    }

    return (' ');
}
