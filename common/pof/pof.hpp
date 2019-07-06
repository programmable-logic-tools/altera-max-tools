
#ifndef POF_HPP
#define POF_HPP

#include <stdint.h>
#include <string>
#include <list>
#include <iterator>
#include "POFBlocks.hpp"

using namespace std;


/**
 * This class handels Altera POF files
 */
class POF
{
private:
    char magic[4];
    char version[4];
    uint32_t blockCount;
    list<POFBlock> blocks;

public:
    /**
     * Construct an empty POF
     */
    POF()
    {
        magic = "POF";
        version = "\x00\x00\x01";
        blockCount = 0;
    };

    /**
     * Free all allocated resources
     */
    ~POF()
    {
        if (blockCount > 0)
        {
            list<POFBlock>::iterator it;
            for (it = blocks.begin(); it != blocks.end(); ++it)
            {
                delete *it;
            }
        }
    }

    /**
     * Import all object properties and blocks from a file
     */
    void importFromFile(string filename);

    /**
     * Import all object properties from a binary stream
     */
    void importFromStream(istream stream);

    /**
     * Save this POF object to a file
     */
    void saveToFile(string filename);

    /**
     * Generate a binary stream from this POF object
     */
    void exportToStream(ostream stream);
};


#endif POF_HPP
