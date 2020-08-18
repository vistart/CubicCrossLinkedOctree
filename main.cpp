
#include "PlyFile.h"
#include "CubicCrossLinkedOctree.h"
#include <iostream>
#include <sstream>
#include <memory>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Invalid File Path!" << endl;
        return 0;
    }
    string file_path(argv[1]);
    unsigned char depth = 8;
    if (argc > 2)
    {
        istringstream str1(argv[2]);
        unsigned int received = 0;
        str1 >> received;
        depth = received & 0xFF;
    }

    // This statement (construct the PlyFile) will read the ply file.
    cout << "Reading the ply file: " << file_path << endl;
    const auto plyfile = make_shared<PlyFile>(file_path);
    cout << endl;

    const auto point_list = plyfile->GetPointList();
    cout << "The last point is: " << *point_list->GetPoints()->back() << endl;

    cout << "Construct the Octree of Point Cloud: " << endl;
    CubicCrossLinkedOctree<PlyVertexList, PlyVertex, PlyFile> octree(point_list, depth);
    //cout << "Hello World!\n";
    return 0;
}