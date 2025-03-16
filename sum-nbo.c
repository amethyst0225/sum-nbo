#include "sum-nbo.h"

uint32_t one_file(char* file)
{
    uint32_t n;
    FILE* fd = fopen(file, "rb");  

    if (!fd)
    {
        printf("error occurred while opening file\n");
        exit(1);
    }

    fseek(fd, 0, SEEK_END);
    long size = ftell(fd);
    fseek(fd, 0, SEEK_SET);  

    if (size < 4)
    {
        printf("file size smaller than 4 bytes\n");
        fclose(fd);
        exit(1);
    }

    fread(&n, sizeof(uint32_t), 1, fd);  
    fclose(fd);

    n = ntohl(n);  

    print_dec(n);
    print_hex(n);

    return n;
}

void many_files(int n, char **files)
{
    uint32_t res = 0;
    
    for (int i = 1; i < n; i++)  
    {
        uint32_t value = one_file(files[i]);
        res += value;
        if (i != n - 1)
            print_plus();
    }
    print_equal();

    print_dec(res);
    print_hex(res);
}

int main(int argc, char* argv[])
{
    
    if (argc < 2)
    {
        printf("Please enter one or more file names");
        return;
    }
    
    if (argc == 2)
        one_file(argv[1]);
    else
        many_files(argc, argv);

    return;
}