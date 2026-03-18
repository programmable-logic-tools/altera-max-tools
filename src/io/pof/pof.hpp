
#ifndef POF_HPP
#define POF_HPP

#include <stdint.h>
#include <string>
#include <list>
#include <iterator>
#include "pofblocks.hpp"

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
    list<POFBlocks::Generic*> blocks;

public:
    /**
     * Construct an empty POF
     */
    POF()
    {
        magic[0] = 'P';
        magic[1] = 'O';
        magic[2] = 'F';
        magic[3] = 0;
        version[0] = 0;
        version[1] = 0;
        version[2] = 1;
        version[3] = 0;
        blockCount = 0;
    };

    /**
     * Initialize this object by importing a file
     */
    POF(string filename): POF() { importFromFile(filename); }

    /**
     * Free all allocated resources
     */
    ~POF()
    {
        if (blockCount > 0)
        {
            list<POFBlocks::Generic*>::iterator it;
            for (it = blocks.begin(); it != blocks.end(); ++it)
            {
                blockCount--;
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
    void importFromStream(istream& stream);

    /**
     * Save this POF object to a file
     */
    void saveToFile(string filename);

    /**
     * Generate a binary stream from this POF object
     */
    void exportToStream(ostream stream);


    /******* Getters and setters ******/

    /**
     * Get the total number of POF blocks in this file
     */
    uint32_t getBlockCount() { return blockCount; }

    /**
     * Append a new POF block to our list of content blocks
     */
    void appendBlock(POFBlocks::Generic* block)
    {
        blocks.push_back(block);
        blockCount++;
    }
};


#endif
