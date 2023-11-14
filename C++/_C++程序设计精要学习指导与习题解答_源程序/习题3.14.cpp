#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(int argc, char *argv[ ])
{
    for (int x = 0; x < argc; x++)
        printf("%s\n", argv[x]);
    return 0;
}


