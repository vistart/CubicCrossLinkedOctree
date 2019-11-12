#include <iostream>
#include <cstdio>
#include "vertex.h"


int main(int argc, char *argv[]) {
    FILE *fp;
    long count = 0;

    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (!(fp = fopen(argv[1], "r")))
    {
        printf("Can't open %s\n", argv[1]);
        exit(1);
    }
    fseek(fp, 0, SEEK_SET);
    printf("File %s has %ld characters\n", argv[1], count);
    std::cout << "Hello, World!" << std::endl;

	fclose(fp);
    return 0;
}