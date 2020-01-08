
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
    char* buffer = NULL;
    uint32_t bufSize = 0;
    uint32_t bitCount = 0;

public:
    Bitstream(uint32_t bitCount) { setBitCount(bitCount); }
    ~Bitstream();


    /************* Getters and setters ************/

    /**
     * Gets the number of bits in this bitstream
     */
    uint32_t getBitCount() { return bitCount; }

    /**
     * Sets the number of bits in this bitstream
     * and adjusts the buffer size accordingly
     */
    void setBitCount(uint32_t newCount);

    /**
     * Gets the number of bytes required to store this bitstream
     *
     * This rounds the number of bits up to a multiple of 8.
     */
    uint32_t getByteCount();

    /**
     * Extracts a particular bit by it's index
     *
     * The MSB is a index 0.
     * true  = 1
     * false = 0
     */
    bool getBit(uint32_t index);

    /**
     * Retrieves the n-th byte from the bitstream buffer
     *
     * The MSB is the left-most within the byte.
     */
    uint8_t getByte(uint32_t byteIndex);
};


#endif
