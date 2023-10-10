#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <windows.h>

#define STRING_SIZE 31

int main(int argc, char const *argv[])
{
    system("cls");

    /*
        printf() 函数将数据输出至标准输出，
        stdout 默认情况下就是终端。
        它的返回值是一个整型，代表了输出字符串的个数。
    */
    printf("Out put to stdout\n");

    /*
        %s 格式项所对应输出的字符必须以一个空字符 '\0' 作为结束标志，
        printf() 函数需要以此定位字符串何时结束。
        不然 printf() 函数将不断打印出其后的字符，直到找到 '\0' 为止。
    */
    int n = 108;
    printf("There %s %d item%s in the list.\n", n != 1 ? "are" : "is", n, n != 1 ? "s" : "");

    
    /*
        两个 printf 产生的结果完全不同：

        第一个 printf 会把字符串 format_str 中任何一个 % 字符视为格式项的标志，
        而其后的字符会被视为格式码，但是转义字符又没有对应的参数，其结果完全不可预测。

        第二个 printf 会打印出任何以空字符结尾的字符串，不受转义字符的影响。
    */
    char format_str[STRING_SIZE] = {"Find %d object and deleted %d.\n"};
    printf(format_str);
    printf("%s", format_str);

    /*
        转义字符 %g 在打印那些不需要按列对齐的浮点数特别有用。
        它在打印对应的数值（必须为 double 或 float 类型）时，
        会去掉该数值尾缀的零，保留六位有效数字 （0.2550000 -> 0.255）
        当然，也会四舍五入 （0.66666... -> 0.666667）
    */
    double pi = 4 * atan(1.0);
    printf("%g %g %g %g\n", 1/1.0, 1/2.0, 1/3.0, 1/4.0, 0.0);
    printf("%f %f %f %f\n", 1/1.0, 1/2.0, 1/3.0, 1/4.0, 0.0);
    printf("PI = %g\n", pi);

    /*
        当然，有一个数的绝对值大于 999999，
        按 %g 的格式打印出来就是用科学计数法打印出来的。
    */
    printf("%g\n", 123456789.0);    /*结果是 123457e+08*/


    FILE *fp = fopen("fprintf_output.txt", "w+");
    char sp_str[STRING_SIZE] = {"0"};
    /*
        fprintf() 函数将数据输出到任意文件，
        因此第一个参数必须是 FILE 类型的指针。
        它的返回值同上，代表了输出字符串的个数。
    */
    int return_value = fprintf(fp, "Out put to any file....\n");
    printf("fprintf return: %d\n", return_value);

    /*
        若 printf 或 fprintf 在写入时出现了一个 I/O 错误，
        将会返回一个负值（例如往一个只读文件里写入数据）
    */

    /*
        如果想将数据输出到另一块内存中，
        可以用 sprintf()，它的第一个参数就是一个指向了字符串数组的指针。
        由于该函数不进行 I/O 操作，因此不会返回负值（当然也不排除有些 C 库的实现会这么做）
        它的返回值同上，代表了输出字符串的个数。
    */
    sprintf(sp_str, "Out put to other memory\n");

    /*接下来看一个有点恐怖的错误*/
#if false
    fprintf("stderr","Error");
#endif
    /*
        如果编译器错误地将 "stderr" 这个字符串常量当成一个文件名来处理,不会直接导致内核转储。

        但是,这种情况下,
        fprintf 调用在执行时可能会触发 segmentation fault 或者 general protection fault。
        原因是它试图将字符串地址当成文件描述符来访问,
        这种非法访问会被 CPU 的内存保护机制拦截,然后向内核报告一个页错误(page fault)。

        页错误通常会使内核终止触发FAULT的进程,而不会直接导致整个系统崩溃。
        但页错误也有可能触发内核转储的情况:

        1.如果 page fault 发生在内核代码中,那么会直接造成内核panic。这时就会转储。
        2.如果 Libvirt 配置了对page fault的监控,当检测到某进程频繁page fault,可能会主动触发内核转储以辅助分析。
        3.如果 page fault 触发了内核的某些bug,导致了严重的不一致状态,内核也可能主动panic并转储。
        4.如果 ophys 配置为对 Oops 自动转储,那么 page fault 产生的 Oops 信息也会导致转储。

        所以编译器错误地处理字符串,通过页错误的副作用,确实有可能导致内核转储。
        但这需要触发额外的内核机制,不像硬件异常那样直接造成系统崩溃。
        这种情况下转储就属于辅助分析,而非必然结果。

        当然，以现代编译器的智能程度来说，
        这种错误是不可能发现不了的。。。
    */

    

    return EXIT_SUCCESS;
}
