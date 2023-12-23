#include "./Buffer.h"

int main(int argc, char const *argv[])
{
    char *testString = (char *)calloc(45, sizeof(byte)); 
    strcpy(testString, "45718934754183758913475913487589347593457AA");

    bufferWrite(testString, strlen(testString));

    free(testString);

    return EXIT_SUCCESS;
}
