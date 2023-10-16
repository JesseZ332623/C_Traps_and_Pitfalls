#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    loop:
        static int i = 0;
        printf("%d\n", i++);

    if (i < INT_MAX / 2)
    {
        goto loop;
    }

    return EXIT_SUCCESS;
}
