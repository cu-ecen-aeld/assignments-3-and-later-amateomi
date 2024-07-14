#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/syslog.h>
#include <sys/types.h>
#include <syslog.h>
#include <unistd.h>

#define ARG_COUNT 3

int main(int argc, char* argv[])
{
    openlog(NULL, 0, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Count of arguments must be equal to %i, but only %i was provived", ARG_COUNT, argc);
        return 1;
    }
    const char* const writefile = argv[1];
    const char* const writestr = argv[2];

    const int fd = open(writefile, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR);
    if (fd < 0) {
        syslog(LOG_ERR, "Failed to open file with path %s: %s", writefile, strerror(errno));
        return 1;
    }
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);
    write(fd, writestr, strlen(writestr));
}
