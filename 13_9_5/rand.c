#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    for (int index = 0; index < ULLONG_MAX; ++index)
    {
        printf("%d", rand() % 2);
    }
    return EXIT_SUCCESS;
}
