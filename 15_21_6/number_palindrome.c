#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*判断一个整数是否为回文数 如：12321 就是回文数*/
bool number_palindrome(int number);

/*翻转字符串*/
bool down_string(char *_str);

bool down_string(char *_str)
{
    if (_str == NULL) { return false; }

    /*声明两个指针指向字符串的首尾*/
    char *_str_bengin = _str;
    char *_str_end = _str + strlen(_str) - 1;

    while ((_str_bengin < _str_end))
    {
        if (*_str_bengin != *_str_end) { return false; }
        char temp_char = *_str_bengin;
        *_str_bengin++ = *_str_end;
        *_str_end-- = temp_char;
    }

    return true;
}

bool number_palindrome(int number)
{
    /*一个数的位数*/
    int digits = 0;
    int temp_number = number;
    char *digit_str = NULL;

    while(temp_number > 0)
    {
        temp_number /= 10;
        ++digits;
    }

    digit_str = (char *)malloc(digits * sizeof(char));
    if (!digit_str) 
    {
        perror("Error");
        return false; 
    }

    sprintf(digit_str, "%d", number);
    if(!down_string(digit_str)) { return false; }
    
    free(digit_str);
    return true;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", number_palindrome(12321));
    printf("%d\n", number_palindrome(14541));
    printf("%d\n", number_palindrome(12361));
    printf("%d\n", number_palindrome(111121));
    
    return EXIT_SUCCESS;
}
