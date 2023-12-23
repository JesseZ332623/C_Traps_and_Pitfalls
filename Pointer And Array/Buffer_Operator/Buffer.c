#include "./Buffer.h"

void flushBuffer()
{
    /*取到当前缓冲区内空余数据之长*/
    int currentLength = bufferPointer - Buffer;

    for (register int index = 0; index < BUFFER_SIZE; ++index) 
    {
        fprintf(stdout, "%c", Buffer[index]);
    }

    memset(Buffer, 0, BUFFER_SIZE);
    bufferPointer = Buffer;
}

void bufferWrite(byte * __ptr, int __n)
{
    while (__n > 0) 
    {
        int dataSize = 0, remainingSize;

        /*若写入的数据量超过了缓冲区的容量，刷新*/
        if (bufferPointer == &Buffer[BUFFER_SIZE]) { flushBuffer(); }

        /*求剩下的缓冲区大小*/
        remainingSize = BUFFER_SIZE - (bufferPointer - Buffer);

        /*使用三目运算符确定要拷贝的数据大小*/
        dataSize = (__n > remainingSize) ? remainingSize : __n;

        memcpy(bufferPointer, __ptr, dataSize);

        bufferPointer += dataSize;
        __ptr += dataSize;
        __n -= dataSize;
    }
}