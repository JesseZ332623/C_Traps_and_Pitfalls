#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define SIZE 15

typedef struct _Value
{
    long int number_a;
    float number_b;
    char string_c[15];
} Value;

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("Value.dat", "w+");

    if (!fp)
    {
        perror("Error");
    }


    Value val_data[2] = 
    {
        {1000000000, 12.50, "Value Data 01."},
        {1000000000, 12.50, "Value Data 01."}
    };

    Value read_data[2];
    memset(read_data, 0, sizeof(Value) * 2);

    printf("Read %d data.\n", fwrite(val_data, sizeof(Value), 2, fp));
    rewind(fp);

    fread(read_data, sizeof(Value), 2, fp);
    printf("%ld %.4f %s\n", read_data[0].number_a, read_data[0].number_b, read_data[0].string_c);

    fclose(fp);

    return EXIT_SUCCESS;
}
