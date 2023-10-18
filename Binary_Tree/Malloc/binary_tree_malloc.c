/**
 * @date 2023_10_18
 * @author Jesse_EC
 * @file binary_tree_malloc.c 
 * 
 * 链式二叉搜索树的实现
*/

#include "./include/binary_tree.h"

void do_pre_order_traverse(Tree_Node *current_node, void (*call_back)(TREE_TYPE _value));

/**
 * 向树中添加一个新值，这个值必须不存在与树中。
 * @param _value 要插入的值
 * @return no return
*/
void insert(TREE_TYPE _value)
{
    /*当前节点*/
    Tree_Node *current_node;

    /*持续跟踪要插入节点的位置*/
    Tree_Node **link;

    link = &tree;

    /*搜索各个节点，找到合适的位置*/
    while ((current_node = *link) != NULL)
    {
        /*根据情况进入 左/右 子树*/
        if (_value < current_node->_value)
        {
            link = &current_node->left;
        }
        else
        {
            assert(_value != current_node->_value);
            link = &current_node->right;
        }
    }

    /*为节点分配空间*/
    current_node = (Tree_Node *)malloc(sizeof(Tree_Node));
    
    /*判断内存是否分配成功*/
    assert (current_node != NULL);

    current_node->_value = _value;
    current_node->left = NULL;
    current_node->right = NULL;

    *link = current_node;
}

/**
 * 查找树中一个特定的值，并返回这个值的地址。
 * @param _value 要找的值，这个值必须在树中。
 * @return TREE_TYPE 类型的指针，如果在树中找不到这个值，则返回 NULL (0)
*/
TREE_TYPE* find(TREE_TYPE _value)
{
    Tree_Node *current_node;

    current_node = tree;

    while (current_node != NULL && current_node->_value != _value)
    {
        if (_value < current_node->_value)
        {
            current_node = current_node->left;
        }
        else
        {
            current_node = current_node->right;
        }
    }

    if (current_node != NULL)
    {
        return &current_node->_value;
    }
    else { return NULL; }
}

/**
 * 二叉树的前序遍历
 * @param call_back 一个回调函数指针，所指向的函数将在树中处理每一个节点时被调用。
 * 节点的值作为参数被传递给这个函数。
 * @return no return
*/
void pre_order_traverse(void (*call_back)(TREE_TYPE _value))
{
    do_pre_order_traverse(tree, call_back);
}

void distroy_tree(Tree_Node *tree)
{
    if (tree != NULL)
    {
        distroy_tree(tree->left);
        distroy_tree(tree->right);

        free(tree);
    }
}

void do_pre_order_traverse(Tree_Node *current_node, void (*call_back)(TREE_TYPE _value))
{
    if (current_node != NULL)
    {
        do_pre_order_traverse(current_node->left, call_back);
        do_pre_order_traverse(current_node->right, call_back);

        call_back(current_node->_value);
    }
}



