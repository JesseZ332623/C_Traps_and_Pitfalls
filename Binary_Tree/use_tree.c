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
    TREE_TYPE _data[] = {1, 2, 3, 4, 5, 6, 7, 8};

    //printf("Tree Head Node address: %p\n", tree + 1);
    for (int index = 0; index < sizeof(_data) / sizeof(TREE_TYPE); ++index)
    {
        insert(_data[index]);
    }
    puts("");
    pre_order_traverse(print_node);
    
    return EXIT_SUCCESS;
}

