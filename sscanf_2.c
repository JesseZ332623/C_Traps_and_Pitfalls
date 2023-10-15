#include <stdio.h>
#include <stdlib.h>

#define _DEFAULT_A 1
#define _DEFAULT_B 2

void function(char *buffer);

/*
    使用 sscanf() 函数处理可变格式的输入
*/
void function(char *buffer)
{
    int a, b, c;

    /*查看传入的字符串中，3 个值是否都已给出*/
    if (sscanf(buffer, "%d %d %d", &a, &b, &c) != 3)
    {
        /*如果没有 则给 a 赋缺省值*/
        a = _DEFAULT_A;

        /*然后继续检查剩下的两个值是否给出*/
        if (sscanf(buffer, "%d %d", &b, &c) != 2)
        {
            /*如果没有 则给 b 赋缺省值*/
            b = _DEFAULT_B;

            /*如果三个数都没有给出，代表这是一个糟糕的输入。。。。*/
            if (sscanf(buffer, "%d", &c) != 1)
            {
                /*向标准错误输出该字符串，并退出程序*/
                fprintf(stderr, "Bad Input: %s", buffer);
                exit(EXIT_FAILURE);
            }
        }
    }
    /*输出 a b c 的值*/
    printf("a = %d, b = %d, c = %d\n", a, b, c);
}

int main(int argc, char const *argv[])
{
    char buffer_str[] = {"10 10000 90"};

    function(buffer_str);

    //function(buffer_str + 2);
    
    return EXIT_SUCCESS;
}
