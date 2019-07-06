
#include "pof.hpp"
#include <iostream>
#include <istream>
#include <fstream>
#include "pofblocks.hpp"


void POF::importFromFile(string filename)
{
    // Open file as stream
    ifstream fs(filename);
    if (fs.fail())
    {
        cerr << "Failed to open " << filename << endl;
        return;
    }

    importFromStream(fs);
}


void POF::importFromStream(istream& stream)
{
    // Import header
    stream.read(magic, 4);
    cout << "File type: " << magic << endl;
    stream.read(version, 4);
    stream.read((char*) &blockCount, 4);
    cout << "Block count: " << blockCount << endl;

    if ((blockCount < 2) || (blockCount > 6))
    {
        cerr << "Warning: Unusual number of blocks: " << blockCount << endl;
    }

    // Import blocks
    while (stream.peek() != EOF)
    {
        cout << "Importing block..." << endl;
        POFBlocks::Generic* b = POFBlocks::importBlock(stream);
        appendBlock(b);
    }
}
