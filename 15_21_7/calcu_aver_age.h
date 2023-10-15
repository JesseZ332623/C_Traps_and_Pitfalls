#ifndef _CALCU_AVER_AGE_H_
#define _CALCU_AVER_AGE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

/*有 3 个家庭*/
#define FAMILY_COUNT 3

/*
    声明 FAMILY_COUNT 个家庭年龄信息的 指针数组，
    到时候由 malloc 动态分配.
*/
static int *family_age_info[FAMILY_COUNT];

/*从文件读出的数据存至此处*/
static int *family_age_out[FAMILY_COUNT];

/*每个家庭的成员数是不同的*/
static int family_members[FAMILY_COUNT];

/*计算出的平均数存至此处*/
static double age_average[FAMILY_COUNT];

/*用户输入家庭成员信息*/
bool get_family_info(const int family_count);

/*将用户输入的数据，写入到文件*/
void write_data_to_file(FILE *fp);

/*将数据文件中的数据读出*/
void read_data_file(FILE *fp);

/*计算年龄平均数*/
void calcu_average();

/*输出家庭成员年龄信息*/
void print_info(FILE *out_stream);

/*释放分配的资源*/
void free_resource();

#endif