#ifndef POFBLOCKS_HPP
#define POFBLOCKS_HPP


#include <stdint.h>
#include <string>
#include <list>
#include <iostream>
#include <istream>

#include "bitstream.hpp"

using namespace std;


namespace POFBlocks
{
    typedef enum
    {
        UNDEFINED = -1,
        CREATOR_SOFTWARE = 1,
        TARGET_DEVICE = 2,
        PROJECT_NAME = 3,
        SECURITY = 5,
        CHECKSUM = 8,
        PROGRAMMING_DATA = 17,
    } pofblock_type_e;

    typedef uint16_t blocktype_t;
    typedef uint32_t blocksize_t;

    /**
     * This is the parent class for all data blocks within an Altera POF file
     */
    class Generic
    {
    private:
        blocktype_t blockType = UNDEFINED;
        blocksize_t blockSize = 0;

    public:
        Generic(blocktype_t type, blocksize_t size)
        {
            blockType = type;
            blockSize = size;
        }
    };


    /**
     * This block type stores the software that created the file
     */
    class CreatorSoftware: public Generic
    {
    private:
        string software = "";

    public:
        CreatorSoftware(blocktype_t, blocksize_t, istream&);
    };


    /**
     * This block type stores the model number of the target device
     */
    class TargetDevice: public Generic
    {
    private:
        string targetDevice = "";

    public:
        TargetDevice(blocktype_t, blocksize_t, istream&);
    };


    /**
     * This block stores the actual data to be written to the target device
     */
    class ProgrammingData: public Generic
    {
    private:
        uint32_t startAddress = 0;
        uint32_t size = 0;
        Bitstream* data;

    public:
        ProgrammingData(blocktype_t, blocksize_t, istream& stream);
    };


    /**
     * Parse the input stream and create ob object of the corresponding block type
     */
    Generic* importBlock(istream&);

} // end namespace


#endif
