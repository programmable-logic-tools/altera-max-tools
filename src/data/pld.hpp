
#ifndef DEVICES_HPP
#define DEVICES_HPP

#include "../pof/pofblocks.hpp"


typedef enum
{
    EPM7032S = 1
} devicetype_e;


/**
 * This is the parent class for all programmable logic devices
 */
class ProgrammableLogicDevice
{
protected:
    /** Number of Logic Array Blocks (LABs) on the die */
    uint16_t lab_count = 0;

    /** The correct number of bits in the bitstream */
    uint32_t bit_count = 0;

    /** Bitstream data buffer */
    Bitstream* bitstream = NULL;

    const uint8_t logic_cells_per_lab = 16;
    const uint8_t global_clock_count = 2;

public:
    ProgrammableLogicDevice() {};
    ~ProgrammableLogicDevice() {};

    /**
     * Import a bitstream from a Programmable Object File (POF)
     * @param filename    Full path to the file that shall be imported
     */
    void importFromPOF(string filename);

    void importFromPOFBlock(POFBlocks::ProgrammingData& pofblock);

    void importFromByteArray(uint8_t* buffer, uint32_t bufsize);
};

#endif
