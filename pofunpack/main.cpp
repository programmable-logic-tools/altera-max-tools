
#include "pof.hpp"
#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
    // TODO: Parse command line arguments

    string filename = "test.pof";

    // Import from file
    POF pof(filename);

    cout << pof.getBlockCount() << endl;

    return 0;
}
