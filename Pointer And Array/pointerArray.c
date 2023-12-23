#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    /*
        在 C 这门比较偏向底层的语言中，
        数组具有二义性，在不同的语境下会表达不同的意思，如下所示：
    */
    int array[4] = {1, 5, 7, 76};       // 一个拥有 4 个元素且每个元素都是 int 类型的数组 array

    /*使用 sizeof 运算符，数组名就代表了整个数组，返回的结果是数组在内存中的大小*/
    printf("The array size = %zd\n", sizeof(array));

    /*而离开了 sizeof 运算符，数组名就代表了数组中第一个元素的地址，也可以使用 '*' '&' 来求数组的第一个元素值和整个数组的地址*/
    printf("The begin of array: %p\tThe address of array: %p\tThe first element of array: %d\n", array, &array, *array);

    int * ptr_1 = array + 3;
    int * ptr_2 = array;

    /*若两个指针保存的地址都在同一个数组内，那么就可以计算出两个指针的偏移量*/
    printf("The distance of ptr_1 to ptr_2: %d\n", abs(ptr_2 - ptr_1));

    return EXIT_SUCCESS;
}
