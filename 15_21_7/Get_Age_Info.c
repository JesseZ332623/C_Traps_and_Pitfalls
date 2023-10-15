#include "calcu_aver_age.h"

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("Family_Age.dat", "w+");
    FILE *out_stream = fopen("Family_Age_Info.txt", "w+");

    if (!fp || !out_stream)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    else if(!get_family_info(FAMILY_COUNT))
    {
        exit(EXIT_FAILURE);
    }

    write_data_to_file(fp);

    rewind(fp);
    read_data_file(fp);

    calcu_average();
    print_info(stdout);
    print_info(out_stream);
    
    fclose(fp);
    fclose(out_stream);
    free_resource();

    return EXIT_SUCCESS;
}
