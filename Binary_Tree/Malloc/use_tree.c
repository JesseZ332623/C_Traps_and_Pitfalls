#include "./include/binary_tree.h"
#include <stdlib.h>

void Print_Node(TREE_TYPE _value);

void Print_Node(TREE_TYPE _value)
{
    printf("%.2lf\t", _value);
}

int main(int argc, char const *argv[])
{
    TREE_TYPE *_data = (TREE_TYPE *)malloc(400000 * sizeof(double));
    

    for (int index = 0; index < 40000; ++index)
    {
        _data[index] = index * 23.341 / 1.3465373 + 1;

        insert(_data[index]);
    }

    pre_order_traverse(Print_Node);
    puts("");

    distroy_tree(tree);
    free(_data);

    return 0;
}
