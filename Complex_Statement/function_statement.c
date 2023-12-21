#include <stdio.h>
#include <time.h>

float function() 
{ 
    printf("A function without argument, return float type data.\n"); 
    return 99.50; 
}
typedef void (*funcPtr)();

/*
    至此，我们已经熟练的掌握了 C 函数指针的使用，接下来玩一个骚操作，
    假设 fpointer 的类型是 (const char * (*)(const char *)) 类型的函数指针，
    那么如何让 *fpointer(); 表达式合法呢？
*/
const char * function_02(const char * _str) { return _str; }
typedef const char * (*_pointer)(const char *);

const float (*fptr)() = function;
_pointer fptr_2 = function_02;

int main(int argc, char const *argv[])
{   
    float number = fptr(); printf("%f\n", number);
    const char _str[] = {"The is a test String.\n"};

    /*
        此时，根据返回优先级，fptr_2 先和 () 结合，变成一个函数，传入参数并执行。
        而后，执行完的返回值再解引用，得到字符串 _str 第一个字符的地址，也就是 T
    */
    printf("The Address of _str: %c\n", *fptr_2(_str));


    /*
        这条语句有些复杂，它的目的是：当计算机启动时，硬件将调用首地址为 0 位置的子例程。

        先将 0 转换成指向无参且无返回值的函数指针类型 (void (*)())0

        再解引用这个函数指针来调用它所指向的函数，由于这里的地址为 0，它会调用地址为 0 的函数。
    */
    //(*(void (*)())0)();

    /*
        当然，自从 C 有了 typedef 关键字后，一切都变得好理解了起来。
        使用 typedef void (*funcPtr)(); 语句， 用 funcPtr 代表 (void (*)()) 类型，
        语句就可以简化为：
    */
    //(*(funcPtr)0)();

    /*
        最后，思考一下，如果表达式 function(); 代表调用函数 function，那这个函数名代表了什么?

        答案是：函数名代表了这个函数的地址。 
    */
    return 0;
}
