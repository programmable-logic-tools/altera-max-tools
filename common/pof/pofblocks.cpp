
#include "pofblocks.hpp"

using namespace std;
using namespace POFBlocks;


Generic* POFBlocks::importBlock(istream& stream)
{
    /*
     * This function is not a class method
     * because we need to peek into the stream
     * before we can know which class to instantiate
     */
    Generic* block = NULL;

    blocktype_t blockType;
    blocksize_t blockSize;

    stream.read((char*) &blockType, 2);
    cout << "Block type: " << blockType << endl;
    stream.read((char*) &blockSize, 4);
    cout << "Block size: " << blockSize << endl;

    switch(blockType)
    {
        case CREATOR_SOFTWARE:
            block = new CreatorSoftware(blockType, blockSize, stream);
            break;
        // TODO: Support more block types
    }

    return block;
}


CreatorSoftware::CreatorSoftware(blocktype_t type, blocksize_t size, istream& stream)
    :Generic(type, size)
{
    cout << "Block stores the software, which created this file: ";
    char* buffer = new char[200];
    stream.read(buffer, size);
    software = buffer;
    cout << software << endl;
}

