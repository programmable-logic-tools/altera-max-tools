
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

    blocktype_t blockType;
    stream.read((char*) &blockType, 2);
    cout << "Block type: " << blockType << endl;

    blocksize_t blockSize;
    stream.read((char*) &blockSize, 4);
    cout << "Block size: " << blockSize << endl;

    Generic* block = NULL;

    switch(blockType)
    {
        case CREATOR_SOFTWARE:
            block = new CreatorSoftware(blockType, blockSize, stream);
            break;

        case TARGET_DEVICE:
            block = new TargetDevice(blockType, blockSize, stream);
            break;

        // TODO: Support more block types

        default:
            cerr << "Warning: Skipping unsupported block type: "<< blockType << endl;
            char* buffer = new char[blockSize];
            stream.read(buffer, blockSize);
            delete buffer;
            break;
    }

    return block;
}


CreatorSoftware::CreatorSoftware(blocktype_t type, blocksize_t size, istream& stream)
    :Generic(type, size)
{
    cout << "Creator software: ";
    char* buffer = new char[200];
    stream.read(buffer, size);
    software = buffer;
    delete buffer;
    cout << software << endl;
}


TargetDevice::TargetDevice(blocktype_t type, blocksize_t size, istream& stream)
    :Generic(type, size)
{
    cout << "Target device: ";
    char* buffer = new char[200];
    stream.read(buffer, size);
    targetDevice = buffer;
    delete buffer;
    cout << targetDevice << endl;
}

