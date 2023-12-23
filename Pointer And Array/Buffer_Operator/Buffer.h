#ifndef _BUFFER_H_
#define _BUFFER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 12    // 设缓冲区大小为 1024 字节 （1 KB）

typedef char byte;

static byte Buffer[BUFFER_SIZE];
static byte *bufferPointer = Buffer;

/**
 * @brief  往缓冲区写入数据，该缓冲区采用完全缓冲，即缓冲区满了后再刷新
 * 
 * @param __ptr 要写入的数据。
 * @param __n   数据的长度
*/
void bufferWrite(byte * __ptr, int __n);

/**
 * @brief 刷新缓冲区，操作如下：
 * 将缓冲区的数据通过 printf 全部输出，
 * 然后使用 memset 清空缓冲区，最后将指针 bufferPointer 移回缓冲区头
*/
void flushBuffer();

#endif