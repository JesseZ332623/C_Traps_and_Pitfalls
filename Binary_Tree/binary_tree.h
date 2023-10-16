#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#define TREE_TYPE int   /*树中每一个节点的类型，当前是 int*/

#define NULL ((void *)0)

/*二叉树所有节点的数量*/
#define TREE_SIZE 100

/*容纳这颗树的数组的最大元素数*/
#define ARRAY_SIZE (TREE_SIZE + 1)

static TREE_TYPE tree[ARRAY_SIZE];

/**
 * 向树中添加一个新值，这个值必须不存在与树中。
 * @param _value 要插入的值
 * @return no return
*/
void insert(TREE_TYPE _value);

/**
 * 查找树中一个特定的值，并返回这个值的地址。
 * @param _value 要找的值，这个值必须在树中。
 * @return TREE_TYPE 类型的指针，如果在树中找不到这个值，则返回 NULL (0)
*/
TREE_TYPE* find(TREE_TYPE _value);

/**
 * 二叉树的前序遍历
 * @param call_back 一个回调函数指针，所指向的函数将在树中处理每一个节点时被调用。
 * 节点的值作为参数被传递给这个函数。
 * @return no return
*/
void pre_order_traverse(void (*call_back)(TREE_TYPE _value));

#endif //BINARY_TREE_H



