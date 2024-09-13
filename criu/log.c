#include "unistd.h"
#include "log.h"
#include "common/compiler.h"

#define DEFAULT_LOGFD STDERR_FILENO
#define LOG_TIMESTAMP (DEFAULT_LOGLEVEL + 1)
#define LOG_BUF_LEN (8 * 1024)
#define EARLY_LOG_BUF_LEN 1024

static unsigned int current_loglevel  = DEFAULT_LOGLEVEL;
static void vprint_on_level(unsigned int, const char *, va_list);




//implementaion starts here
static void vprint_on_level(unsigned int loglevel, const char *format, va_list params)
{
    int fd, size, ret, off = 0;
    int _errno = errno;

    if(unlikely(loglevel == LOG_MSG)) {
        fd = STDOUT_FILENO;
        off = buff_off;
    }
}
