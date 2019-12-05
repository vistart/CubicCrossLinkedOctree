
#include "file_format/ply/PlyFile.h"
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid File Path!" << endl;
		return 0;
	}
	string file_path(argv[1]);
	unique_ptr<PlyFile> plyfile = make_unique<PlyFile>(file_path);
    //cout << "Hello World!\n";
}