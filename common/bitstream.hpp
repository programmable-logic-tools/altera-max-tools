
#ifndef BITSTREAM_HPP
#define BITSTREAM_HPP

#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <iostream>

using namespace std;


/**
 * This class stores a bitstream
 * and makes all bits accessible individually
 *
 * The MSB at index 0.
 * The MSB within a byte is the left-most (mask: 0x80).
 */
class Bitstream
{
private:
    char* data = NULL;
    uint32_t bitCount = 0;

public:
    Bitstream(uint32_t bitCount) { setBitCount(bitCount); }
    ~Bitstream()
    {
        if (data != NULL)
            free(data);
    }

    /************* Getters and setters ************/

    /**
     * Gets the number of bits in this bitstream
     */
    uint32_t getBitCount() { return bitCount; }

    /**
     * Sets the number of bits in this bitstream
     * and adjusts the buffer size accordingly
     */
    void setBitCount(uint32_t newCount)
    {
        bitCount = newCount;
        // TODO: Do not discard already stored content
        if (data != NULL)
            free(data);
        data = (char*) malloc(getByteCount());
    }

    /**
     * Gets the number of bytes required to store this bitstream
     *
     * This rounds the number of bits up to a multiple of 8.
     */
    uint32_t getByteCount()
    {
        return (uint32_t) ceil(((float) bitCount) / 8.0);
    }

    /**
     * Extracts a particular bit by it's index
     *
     * The MSB is a index 0.
     * true  = 1
     * false = 0
     */
    bool getBit(uint32_t index)
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

    /**
     * Retrieves the n-th byte from the bitstream buffer
     *
     * The MSB is the left-most within the byte.
     */
    uint8_t getByte(uint32_t byteIndex)
    {
        if (byteIndex >= getByteCount())
        {
            cerr << "Error: Attempt to read beyond end of bitstream" << endl;
            return 0xFF;
        }
        return data[byteIndex];
    }
};


#endif
