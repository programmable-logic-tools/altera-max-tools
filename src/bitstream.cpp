
#include "bitstream.hpp"


Bitstream::~Bitstream()
{
    if (buffer != NULL)
        free(buffer);
    bufSize = 0;
}


void Bitstream::setBitCount(uint32_t newCount)
{
    bitCount = newCount;
    uint32_t newByteCount = getByteCount();
    if (buffer == NULL)
    {
        buffer = (char*) malloc(newByteCount);
        bufSize = newByteCount;
    }
    else
    {
        // Is there enough space in the existing buffer?
        if (bufSize < newByteCount)
        {
            // Allocate some more, so we don't need to reallocate for every byte
            buffer = (char*) realloc(buffer, newByteCount+200);
            bufSize = newByteCount+200;
        }
    }
}


uint32_t Bitstream::getByteCount()
{
    return (uint32_t) ceil(((float) bitCount) / 8.0);
}


bool Bitstream::getBit(uint32_t index)
{
    if (index >= bitCount)
    {
        cerr << "Error: Read attempt beyond end of bitstream" << endl;
        return 1; // 1 is the default state for erased flash memory bits
    }
    uint8_t b = getByte(index / 8);
    uint8_t remainder = index % 8;
    uint8_t mask = (0x80 >> remainder);
    return ((b & mask) > 0) ? true : false;
}


uint8_t Bitstream::getByte(uint32_t byteIndex)
{
    if (byteIndex >= getByteCount())
    {
        cerr << "Error: Attempt to read beyond end of bitstream" << endl;
        return 0xFF;
    }
    return buffer[byteIndex];
}
