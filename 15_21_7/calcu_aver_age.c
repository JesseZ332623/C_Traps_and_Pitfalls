#include "calcu_aver_age.h"

bool get_family_info(const int family_count)
{
    for (int index = 0; index < family_count; ++index)
    {
        /*用户输入家庭成员数*/
        printf("Family [%d]: Enter your family member: ", index + 1);
        scanf("%d", &family_members[index]);

        /*动态分配成员数*/
        printf("OK! Family [%d] has %d menbers.\n", index + 1, family_members[index]);
        family_age_info[index] = (int *)malloc(family_members[index] * sizeof(int));

        if (!family_age_info[index])
        {
            perror("Error");
            return false;
        }

        /*输入 各个家庭成员的年龄*/
        printf("Than, Enter Your member age:\n");
        for (int member = 0; member < family_members[index]; ++member)
        {
            printf("Enter the Member [%d] age: ", member + 1);
            scanf("%d", &family_age_info[index][member]);

            // while (getchar() != '\n') { continue; }
        }

        printf("OK! Family [%d] info enter complite!\n", index + 1);

        /*等待 1s 并清屏后再输入下一个家庭的信息*/
        Sleep(1000);
        system("Cls");

        while (getchar() != '\n') { continue; }
    }

    return true;
}

/*将用户输入的数据，写入到文件*/
void write_data_to_file(FILE *fp)
{
    for (int index = 0; index < FAMILY_COUNT; ++index)
    {
        fwrite(family_age_info[index], sizeof(int), family_members[index], fp);
    }
}

/*将数据文件中的数据读出*/
void read_data_file(FILE *fp)
{
    for (int index = 0; index < FAMILY_COUNT; ++index)
    {
        family_age_out[index] = (int *)malloc(family_members[index] * sizeof(int));
        fread(family_age_out[index], sizeof(int), family_members[index], fp);
    }
}

/*计算年龄平均数*/
void calcu_average()
{
    double temp_average = 0.00000;
    for (int index = 0; index < FAMILY_COUNT; ++index)
    {
        temp_average = 0.00000;
        for (int member = 0; member < family_members[index]; ++member)
        {
            temp_average += family_age_out[index][member];
        }
        age_average[index] = temp_average / family_members[index];
    }
}

/*输出家庭成员年龄信息，输出示例如下：*/
/*
    Show the age info:
    Family [1]: 3 members:
    45      42      22
    Average age: 36.33
    Family [2]: 5 members:
    36      35      7       3       12    
    Average age: 18.60
    Family [3]: 2 members:
    22      20
    Average age: 21.00
*/
void print_info(FILE *out_stream)
{
    fprintf(out_stream, "Show the age info:\n");
    for (int f_count = 0; f_count < FAMILY_COUNT; ++f_count)
    {
        fprintf(out_stream, "Family [%d]: %d members:\n", f_count + 1, family_members[f_count]);
        for (int fm_count = 0; fm_count < family_members[f_count]; ++fm_count)
        {
            fprintf(out_stream, "%d\t", family_age_out[f_count][fm_count]);
        }
        fprintf(out_stream,"\nAverage age: %5.2lf\n", age_average[f_count]);
    }
}

/*释放分配的资源*/
void free_resource()
{
    for (int count = 0; count < FAMILY_COUNT; ++count)
    {
        free(family_age_info[count]);
        free(family_age_out[count]);
    }
}