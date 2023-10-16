#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*这个文件主要展示 sscanf 函数的用法*/

int main(int argc, char const *argv[])
{
    int index = 0;
    double object_data = 0.0000;
    char data_discrible[50] = {"0"};

    char *format_string  = (char *)malloc(50);

    /*使用 fgets 从标准输入中读取字符串并存入 format_string 中*/
    puts("Enter the\n(int)<index> : (double)<object_data> (string)<data_discrible>");
    fgets(format_string, 50, stdin);
    
    /*
        scanf() 函数从标准输入中读取数据，并赋值给其它变量。

        与 scanf() 不同的是，sscanf() 函数会根据传入的格式化字符串，
        从 format_string 中读取数据，并依次赋值给其他变量。
    */
    sscanf(format_string, "%d %lf %s", &index, &object_data, data_discrible);

    printf("[%d]: [%lf](%s)\n", index, object_data, data_discrible);
    
    free(format_string);
    return EXIT_SUCCESS;
}
