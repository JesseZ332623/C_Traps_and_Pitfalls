#include "./binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

void print_node(TREE_TYPE _value);

void print_node(TREE_TYPE _value)
{
    printf("%d\t", _value);
}

int main(int argc, char const *argv[])
{
    int _data[3] = {4, 2, 1};

    printf("Tree Head Node address: %p\n", tree);
    for (int index = 0; index < 3; ++index)
    {
        insert(_data[index]);
        printf("%p\t", find(_data[index]));
    }
    puts("");
    pre_order_traverse(print_node);
    
    return EXIT_SUCCESS;
}
