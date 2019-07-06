#ifndef POFBLOCKS_HPP
#define POFBLOCKS_HPP


#include <stdint.h>
#include <string>
#include <list>

#include "bytestream.hpp"

using namespace std;


namespace POFBlocks
{
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
     * This is the parent class for all data blocks within an Altera POF file
     */
    class Generic
    {
    private:
        pofblock_type_e type = UNDEFINED;
        uint32_t size = 0;

    public:
        Generic (istream& stream);
    };


    /**
     * This block type stores the software that created the file
     */
    class CreatorSoftware : public Generic
    {
    private:
        string software = "";

    public:
        CreatorSoftware (istream& stream);
    };


    /**
     * This block stores the actual data to be written to the target device
     */
    class ProgrammingData : public Generic
    {
    private:
        uint32_t startAddress = 0;
        uint32_t size = 0;
        ByteStream data;

    public:
        ProgrammingData (istream& stream);
    };

} // end namespace


#endif
