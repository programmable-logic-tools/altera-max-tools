
#ifndef BITSTREAM_HPP
#define BITSTREAM_HPP

#include <stdint.h>
#include <iostream>

using namespace std;


class ByteStream
{
private:
    uint32_t byteCount = 0;

public:
    ByteStream(istream& stream, uint32_t size);
};


#endif
