#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *buffer = NULL;
    size_t bufsize = 0;

    getline(&buffer, &bufsize, stdin);

    printf("%s\n", buffer);

    free(buffer);
    return 0;
}
