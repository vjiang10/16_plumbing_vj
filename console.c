#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
    int fd1 = open("toProcess", O_WRONLY);
    int fd2 = open("toConsole", O_RDONLY);

    char str[256];

    printf("returns UPPERCASE str copy \n");
    while(1) {
        printf("enter line: ");
        int size = sizeof(str);
        fgets(str, size, stdin);
        write(fd1, str, size);
        read(fd2, str, size);
        printf("Result: %s\n", str);
    }

    close(fd1);
    close(fd2);

    return 0;
}