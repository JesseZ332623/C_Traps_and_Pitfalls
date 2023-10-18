/**
 * @date 2023_10_17
 * Determine the value of an expression
 * 判断各表达式的值
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
#include <assert.h>

#define SQRT(x)  ((x) * (x))

/*
    一个结构体 Pointer 有两个 int 类型的元素 x 和 y
*/
typedef struct _Ptr
{
    int x;
    int y;
} Pointer;

volatile void signal_handle();
long long int my_abs(long long int _value);

volatile void signal_handle()
{
    fprintf(stderr, "Cross border visits...\n");
}

long long int my_abs(long long int _value)
{
    if (_value < 0) { return -_value; }
    else { return _value; }
}

int main(int argc, char *argv[])
{   
    char _str_ptr[] = "/user/temp/xxxxxxxxxxxxxxxxx";
    char _num_str[] = "12345abcderf";
    char *_ptr_tol;

    printf("%lld", my_abs(-INT_MAX));

    //*(_str_ptr + strlen(_str_ptr) + 1) = 'a';

    printf("%ld\n", strtol(_num_str, &_ptr_tol, 10));
    printf("%ld\n", strtol("12345", NULL, 10));

    if (*_ptr_tol != '\0') 
    {
        printf("After digits: %s\n", _ptr_tol);
    }

    

    //atexit(signal_handle);

    return EXIT_SUCCESS;
}
