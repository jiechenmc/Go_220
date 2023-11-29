#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char *buffer = NULL;
    size_t bufsize = 0;

    int managed_arr[5] = {0};
    int managed_arr_ptr = 0;

    // SIMPLE MANAGER TO ADD SOMETHING TO AN ARRAY
    while (getline(&buffer, &bufsize, stdin) != EOF)
    {
        if (!strcmp(buffer, "ADD\n"))
        {
            fprintf(stderr, "ADD COMMAND RECV\n");
            managed_arr[managed_arr_ptr++] = 1;
        }
        else if (!strcmp(buffer, "REMOVE\n"))
        {
            fprintf(stderr, "REMOVE COMMAND RECV\n");
            managed_arr[managed_arr_ptr--] = 0;
        }
        else if (!strcmp(buffer, "SHOW\n"))
        {
            fprintf(stderr, "REMOVE COMMAND RECV\n");
            for (int i = 0; i < 5; i++)
            {
                printf("%d |", managed_arr[i]);
            }
            printf("\n");
        }
    }

    free(buffer);
    return 0;
}
