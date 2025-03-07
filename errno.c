#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <errno.h>
#include <string.h>
int main() {

    errno = 0;
    FILE* file = fopen("does_not_exist.txt", "r");

    if (!file) {
        printf("Error opening file: %d %s\n", errno,  strerror(errno));
    }

    errno = 0;

    return 0;
}