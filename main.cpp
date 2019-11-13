#include <iostream>
#include <cstdio>
#include "file_format/ply/vertex.h"
#include <iomanip>


int main(int argc, char *argv[]) {
    FILE *fp;

    if (argc != 2)
    {
		std::cout << "Usage: " << argv[0] << " filename" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (!(fp = fopen(argv[1], "r")))
    {
		std::cout << "Can't open " << argv[1] << std::endl;
        exit(1);
    }
    fseek(fp, 0, SEEK_SET);
    std::cout << "Hello, World!" << std::endl;

	Vertex** vlist_local = read_file(fp);
	std::cout << "vlist digest:" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setiosflags(std::ios::fixed) << std::setw(12) << vlist_local[i][0].x << std::setw(12) << vlist_local[i][0].y << std::setw(12) << vlist_local[i][0].z;
		std::cout << std::endl;
	}
	
	fclose(fp);
    return 0;
}
