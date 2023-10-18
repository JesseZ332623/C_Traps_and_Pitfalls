/**
 * @date 2023_10_18
 * @author Jesse_EC
 * @file binary_tree.h 
 * 
 * 链式二叉搜索树接口的声明
*/

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <assert.h>
#include <malloc.h>
#include <stdio.h>

#define TREE_TYPE double   /*树中每一个节点的类型，当前是 double*/

#define NULL ((void *)0)

/*
    TREE_NODE 节点 
    包含了一个值以及指向左右子节点的指针
*/
typedef struct TREE_NODE
{
    TREE_TYPE _value;
    struct TREE_NODE *left;
    struct TREE_NODE *right;

} Tree_Node;

/*
    指向树根节点的指针
*/
static Tree_Node *tree;

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

/**
 * 使用完毕后，销毁整棵树。
 * @param tree 一棵树头节点的指针
 * @return no return
*/
void distroy_tree(Tree_Node *tree);

#endif //BINARY_TREE_H



