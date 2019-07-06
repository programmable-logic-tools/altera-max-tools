
#ifndef POFBLOCKS_HPP
#define POFBLOCKS_HPP

#include <stdint.h>
#include <string>
#include <list>

#include "ByteStream.hpp"

using namespace std;


typedef enum
{
    UNDEFINED = -1,
    CREATOR_SOFTWARE = 1,
    TARGET_DEVICE = 2,
    PROJECT_NAME = 3,
    SECURITY_SWITCH = 5,
    CHECKSUM = 8,
    PROGRAMMING_DATA = 17,
} pofblock_type_e;


/**
 * This class handles one data block within an Altera POF file
 */
class POFBlock
{
private:
    pofblock_type_e type = UNDEFINED;
    uint32_t size = 0;

public:
    POFBlock(istream& stream);
};


class BlockCreatorSoftware: public POFBlock
{
private:
    string software = "";

public:
    BlockCreatorSoftware(istream& stream);
};


class BlockProgrammingData: public POFBlock
{
private:
    uint32_t startAddress = 0;
    uint32_t size = 0;
    ByteStream data;

public:
    BlockProgrammingData(istream& stream);
};


#endif
