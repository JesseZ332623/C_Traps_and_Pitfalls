#include "./binary_tree.h"
#include <assert.h>

static TREE_TYPE tree[ARRAY_SIZE];

/**
 *  计算一个节点左孩子的 下标
 *  @param current 当前节点的下标
 *  @return 当前节点左孩子节点的下标
 */
static int left_child(int current);

/**
 *  计算一个节点右孩子的 下标
 *  @param current 当前节点的下标
 *  @return 当前节点右孩子节点的下标
 */
static int right_child(int current);

/**
 * 执行一层前序遍历，此函数用于保存当前正在处理的节点的信息。
 * @param current_index 当前节点的下标
 * @param call_back 一个回调函数指针，所指向的函数将在树中处理每一个节点时被调用。
 * 节点的值作为参数被传递给这个函数。
 * @return no return
*/
static void do_pre_order_traverse(int current_index, void (*call_back)(TREE_TYPE _value));

static int left_child(int current)
{
    return current * 2;
}

static int right_child(int current)
{
    return current * 2 + 1;
}

void insert(TREE_TYPE _value)
{
    int current_index;

    /*
        需要确保值不能为 0，因为 0 代表了一个未使用的节点。
    */
    assert(_value != 0);

    /*从根节点开始*/
    current_index = 1;

    /*开始遍历节点，直到找到空节点为止。*/
    while (tree[current_index] != 0)
    {
        /*根据情况，进入叶节点或右子树。（确保不能有重复的值）*/
        if (_value < tree[current_index])
        {
            current_index = left_child(current_index);
        }
        else
        {
            assert(_value != tree[current_index]);
            current_index = right_child(current_index);
        }
        /*如果算出来的下标超过了数组的容量，也是不允许的。*/
        assert(current_index < ARRAY_SIZE);
    }
    /*找到合适的下标时，将值赋给它，节点插入成功*/
    tree[current_index] = _value;
}

TREE_TYPE* find(TREE_TYPE _value)
{
    int current_index = 1;

    /*当前下标不应该超过数组的大小，并且当前索引对应的值不等于用户传入的值*/
    while (current_index < ARRAY_SIZE && tree[current_index] != _value)
    {
        /*根据情况，进入左/右子树*/
        if (_value < tree[current_index])
        {
            current_index = left_child(current_index);
        }
        else
        {
            current_index = right_child(current_index);
        }
    }
    if (current_index < ARRAY_SIZE)
    {
        return tree + current_index;
    }
    else{ return NULL; }
}

void pre_order_traverse(void (*call_back)(TREE_TYPE _value))
{
    do_pre_order_traverse(1, call_back);
}

static void do_pre_order_traverse(int current_index, void (*call_back)(TREE_TYPE _value))
{
    /*当前下标不应该超过数组的大小，并且当前索引对应的值不等于用户传入的值*/
    if (current_index < ARRAY_SIZE && tree[current_index] != 0)
    {
        do_pre_order_traverse(left_child(current_index), call_back);
        do_pre_order_traverse(right_child(current_index), call_back);
        call_back(tree[current_index]);
    }
}