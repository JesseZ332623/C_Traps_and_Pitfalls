#include "./about_signal.h"

void show_number(int number)
{
    printf("In parameter %d\n", number);
}

void function(int number, _Func func)
{
    printf("Call function: show_number()\n");
    func(number);
}

void signalHandler(int _signal)
{
    if (_signal == SIGSEGV)
    {
        fprintf(stderr, "Caught a SIGSEGV - array index out of bounds.\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char const *argv[])
{
    int  _data[10] = {1, 6, 8, 245, 5};

    /*使用 signal 注册这个越界访问信号函数*/
    signal(SIGSEGV, signalHandler);

    /*出现越界访问，放出非法访问信号*/
    _data[100] = 100;   raise(SIGSEGV);

    return EXIT_SUCCESS;
}
