#ifndef _ABOUT_SIGNAL_H_
#define _ABOUT_SIGNAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>

/*
    要使用 signal 库，
    就需要对指向函数的指针有所了解，先来复习一下：
*/
/*
    使用 typedef 关键字创建新类型 _Func，(void (*)(int)) 类型
*/
typedef void (* _Func)(int);

void show_number(int number);

/**
 * @brief 传入一个函数和一个数字，调用 func 指向的函数并输出相关信息。
 * 
 * @param number 要输入的数字
 * @param func   指向一个有 int 类型参数但无返回值的函数指针
 * 
 * @return non-return
*/
void function(int number, _Func func);

/*
    复习了函数指针相关的知识，接下来可以开始使用 signal 库了。
    这个库的内容其实很少，先看 signal 函数的原型：

    __p_sig_fn_t __cdecl signal(int _SigNum, __p_sig_fn_t _Func);

    __p_sig_fn_t 是一个指向了有一个 int 类型参数且返回值为 void 的函数指针
    它的 typedef 如下：

        typedef void (*__p_sig_fn_t)(int);

    signa 库中将一个 数字 强行转换成一个 __p_sig_fn_t 类型的指针，
    去访问 CPU 的终端向量表的索引，然后再调用相应的信号处理函数。

    库中定义的信号宏如下：
    #define SIG_DFL (__p_sig_fn_t)0     默认的信号处理动作
    #define SIG_IGN (__p_sig_fn_t)1     忽略该信号
    #define SIG_GET (__p_sig_fn_t)2     从中断向量表获取该信号对应的处理函数地址
    #define SIG_SGE (__p_sig_fn_t)3     信号处理函数地址大于等于该值时表示自定义信号处理函数
    #define SIG_ACK (__p_sig_fn_t)4     确认收到的信号
    #define SIG_ERR (__p_sig_fn_t) - 1  信号错误

    #define SIGINT 2                    中断（交互性）信号，通常来自键盘按下 Ctrl + C
    #define SIGILL 4                    非法指令信号
    #define SIGABRT_COMPAT 6            兼容的程序终止信号
    #define SIGFPE 8                    浮点异常信号
    #define SIGSEGV 11                  段错误 / 非法内存访问信号
    #define SIGTERM 15                  终止信号
    #define SIGBREAK 21                 Ctrl + Break 信号（为了兼容古老的 Windows 系统特有的快捷键）
    #define SIGABRT 22                  程序终止信号
    #define SIGABRT2 22                 同上

    首先来写一个检测越界访问（非法访问内存）的函数：
*/

/**
 * @brief 一个用于检测信号的函数，作为 signle 函数的参数使用
 * 
 * @param _signal   signle 函数传入的信号宏
*/
void signalHandler(int _signal);


#endif