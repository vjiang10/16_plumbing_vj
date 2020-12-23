#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    mkfifo("toProcess", 0644);
    mkfifo("toConsole", 0644);
    
    int fd1 = open("toProcess", O_RDONLY);
    int fd2 = open("toConsole", O_WRONLY);

    char str[256];

    while(1) {
        int size = sizeof(str);
        read(fd1, str, size);
        int i;
        for (i = 0; str[i]; i++) str[i] = str[i] - 32;
        write(fd2, str, size);
    }
    
    close (fd1);
    close (fd2);

    return 0;
}

